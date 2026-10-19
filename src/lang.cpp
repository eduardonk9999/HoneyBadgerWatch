#include "lang.h"

namespace Lang {

static uint8_t s_lang = EN;

// [StringId] = { EN, PT_BR }. No accents in the PT column (font-glyph safety,
// see lang.h). UI chrome only -- technical terms never live here.
static const char* const T[STR_COUNT][COUNT] = {
    /* BTN_DESK       */ { "[ DESK ]",   "[ MESA ]"   },
    /* BTN_CLR        */ { "[ CLR ]",    "[ LIMPAR ]" },
    /* BTN_BACK       */ { "[ BACK ]",   "[ VOLTAR ]" },
    /* GRP_APPEARANCE */ { "APPEARANCE", "APARENCIA"  },
    /* GRP_SYSTEM     */ { "SYSTEM",     "SISTEMA"    },
    /* ROW_LANGUAGE   */ { "LANGUAGE",   "IDIOMA"     },
    /* GRP_BEHAVIOR   */ { "BEHAVIOR",     "CONDUTA"       },
    /* GRP_DESK       */ { "DESK",         "MESA"          },
    /* GRP_WATCH      */ { "WATCH",        "RELOGIO"       },
    /* GRP_FONTS      */ { "TEXT SIZE",    "TEXTO"         },
    /* ROW_BORING     */ { "BORING MODE",  "MODO SIMPLES"  },
    /* ROW_ALERT_FILTER*/{ "ALERT FILTER", "FILTRO ALERTA" },
    /* ROW_AUTO_SNOOZE*/ { "AUTO SNOOZE",  "AUTO SONECA"   },
    /* ROW_TYPE_FILTER*/ { "TYPE FILTER",  "FILTRO TIPO"   },
    /* ROW_IGNORED    */ { "IGNORED",      "IGNORADOS"     },
    /* ROW_SOUND      */ { "SOUND",        "SOM"           },
    /* STR_ON         */ { "ON",           "LIG"           },
    /* STR_OFF        */ { "OFF",          "DESL"          },
    /* STR_ALL        */ { "ALL",          "TUDO"          },
    /* STR_ALERTS     */ { "ALERTS",       "ALERTAS"       },
    /* STR_AFTER5     */ { "AFTER 5",      "APOS 5"        },
    /* STR_AFTER10    */ { "AFTER 10",     "APOS 10"       },
    /* STR_HIGH_ONLY  */ { "HIGH ONLY",    "SO ALTA"       },
    /* BTN_UP         */ { "[ UP ]",       "[ ACIMA ]"     },
};

void set(uint8_t l)       { s_lang = (l < COUNT) ? l : EN; }
uint8_t current()         { return s_lang; }
const char* name(uint8_t l) { return (l == PT_BR) ? "PT-BR" : "EN"; }

const char* trIn(StringId id, uint8_t l) {
    return T[(id < STR_COUNT) ? id : 0][(l < COUNT) ? l : EN];
}
const char* tr(StringId id) { return trIn(id, s_lang); }
const char* onOff(bool on)  { return tr(on ? STR_ON : STR_OFF); }

}
