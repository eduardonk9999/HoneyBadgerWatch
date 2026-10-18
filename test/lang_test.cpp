#include "lang.h"
#include <cstring>
#include "test_util.h"

using namespace Lang;

int main() {
    suite("The string table is complete");
    {
        bool filled = true, distinct = true;
        for (int i = 0; i < STR_COUNT; i++) {
            const char* en = trIn((StringId)i, EN);
            const char* pt = trIn((StringId)i, PT_BR);
            if (!en || !en[0] || !pt || !pt[0]) filled = false;
            if (en && pt && strcmp(en, pt) == 0) distinct = false;  // chrome: the two should differ
        }
        ck("every id has a non-empty EN and PT-BR", filled);
        ck("EN and PT-BR differ for every row", distinct);
    }

    suite("tr follows the current language");
    {
        set(EN);
        ck("current is EN", current() == EN);
        ck("EN desk button is [ DESK ]", !strcmp(tr(BTN_DESK), "[ DESK ]"));
        set(PT_BR);
        ck("current is PT-BR", current() == PT_BR);
        ck("PT desk button is [ MESA ]", !strcmp(tr(BTN_DESK), "[ MESA ]"));
        ck("PT system header is SISTEMA", !strcmp(tr(GRP_SYSTEM), "SISTEMA"));
    }

    suite("names and clamping");
    {
        ck("name(EN) is EN", !strcmp(name(EN), "EN"));
        ck("name(PT_BR) is PT-BR", !strcmp(name(PT_BR), "PT-BR"));
        set(99);
        ck("an out-of-range language clamps to EN", current() == EN);
        ck("trIn clamps a bad id rather than reading past the table",
           trIn((StringId)9999, EN) != nullptr);
    }

    return report();
}
