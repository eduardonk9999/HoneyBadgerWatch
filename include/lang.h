#pragma once
#include <stdint.h>

// HoneyBadgerWatch -- UI language (i18n).
//
// Two languages: English (EN) and Brazilian Portuguese (PT_BR). This table
// holds UI CHROME ONLY. Technical terms stay in English in BOTH languages by
// design -- detection type names (FLOCK, DEAUTH, AIRTAG), acronyms (MAC, RSSI,
// OUI, SSID, LoRa, GPS) and firmware verbs (flash, scan) are never translated
// and so never appear here.
//
// The PT column avoids accented characters until the display fonts are
// confirmed to carry those glyphs (a follow-up); README and docs use accents
// freely.
//
// The runtime current language lives here; Settings owns persistence and calls
// set() on load and on change, so the firmware reads one source of truth and
// the host tests can drive it without the NVS shim.
namespace Lang {

enum : uint8_t { EN = 0, PT_BR = 1, COUNT = 2 };

enum StringId : uint16_t {
    BTN_DESK = 0,
    BTN_CLR,
    BTN_BACK,
    GRP_APPEARANCE,
    GRP_SYSTEM,
    ROW_LANGUAGE,
    GRP_BEHAVIOR,
    GRP_DESK,
    GRP_WATCH,
    GRP_FONTS,
    ROW_BORING,
    ROW_ALERT_FILTER,
    ROW_AUTO_SNOOZE,
    ROW_TYPE_FILTER,
    ROW_IGNORED,
    ROW_SOUND,
    STR_COUNT
};

void        set(uint8_t lang);              // clamps to a valid language
uint8_t     current();
const char* name(uint8_t lang);             // "EN" / "PT-BR"
const char* trIn(StringId id, uint8_t lang);
const char* tr(StringId id);                // in the current language

}
