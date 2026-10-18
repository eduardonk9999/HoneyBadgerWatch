# HoneyBadgerWatch

> Surveillance-device detector for the ESP32 "Cheap Yellow Display" — built for Brazil, fearless like the honey badger.

<p align="center">
  <img src="docs/texugo.png" width="200" alt="Texugo, the honey badger mascot, in pixel art">
</p>

<p align="center">
  <b>🇧🇷 <a href="README.pt-BR.md">Leia em português</a></b>
</p>

HoneyBadgerWatch is a handheld scanner that sniffs WiFi and Bluetooth for the
wireless signatures of surveillance hardware — license-plate cameras, body
cameras, card skimmers, hidden trackers, drones — and shouts when it finds one.
It runs **standalone on a ~$15 board**: no PC, no app, just plug it into USB.

The twist is the attitude. The mascot is **Texugo**, a honey badger — the
animal that does not care, that walks up to anything — wrapped in a **matrix
green terminal** and a dose of **early-2000s raiz-internet** nostalgia. The name
is a wink to his two moods: **"do mel, ou mal"** (sweet, or mean).

> **Honey badger don't care.**

---

## This is a fork — credit where it's due

HoneyBadgerWatch is a fork of **[SquachWatch-CYD](https://github.com/skizzophrenic/SquachWatch-CYD)**
by **skizzophrenic**, an excellent open-source project (GPLv3) that does all of
the hard radio and UI work. We stand on their shoulders. The entire detection
engine, the OTA updater, the board support, the PC emulator and the test suite
come from there, unchanged at the core.

**What HoneyBadgerWatch adds** is a Brazilian lens: local surveillance vendors,
the Brazilian LoRa band, a Portuguese/English interface, and a brand of our own.
If you're in the US or anywhere else, the upstream project may fit you better —
go star it.

---

## What it detects

Inherited from the upstream engine — cameras (Flock, Axon, generic IP
cameras, Ring), trackers (AirTag, Tile, SmartTag, Google Find My), drones
(Remote ID, decoded), plate readers, recording glasses, Bluetooth card
skimmers, gunshot sensors, and live WiFi attacks (**deauth floods**, **evil
twins**) plus pentest gear (Flipper Zero, Pwnagotchi, WiFi Pineapple).

Each signature carries an honest **confidence grade** — High only when the
hardware prefix is registered to the actual vendor in the IEEE registry, Low
when it's a shared chip-maker block that half the world uses.

### 🇧🇷 The Brazilian additions

Because the US-focused originals miss what actually watches you here:

| What | Vendors / detail |
|---|---|
| **ALPR / traffic** | Pumatronix (ITSCAM) |
| **Facial / access control** | Control iD, Grupo Digicon |
| **Cameras (local + ubiquitous)** | Intelbras, plus reinforced Hikvision / Dahua / Ezviz / Axis / Verkada / Avigilon |
| **Public monitoring** | Smart Sampa, Muralha (run on the camera vendors above) |
| **LoRa** | Brazilian **BR_902** band (902–907.5 / 915–928 MHz, ANATEL ISM) |

All OUIs were read straight from the **official IEEE MA-L registry**, not copied
from another detector — and the verified false matches are documented and left
out (e.g. `00:07:D9` is SpliceCom in the UK, **not** the Brazilian radar maker
Splice). The full table is in **[docs/SIGNATURES-BR.md](docs/SIGNATURES-BR.md)**.

---

## Language

The interface ships in **Portuguese and English** (toggle in Settings), so the
same device makes sense to creators and users in both countries. **Technical
terms stay in English in both languages** — detection type names (`FLOCK`,
`DEAUTH`, `AIRTAG`), acronyms (`MAC`, `RSSI`, `OUI`, `SSID`, `LoRa`) and
firmware verbs (`flash`, `scan`) — so the LOG and alert screens read the same
everywhere.

---

## Status

> 🚧 **Early days.** The fork is scaffolded and the inherited core builds and
> passes its tests. The Brazilian rebrand is in progress.

- ✅ Fork scaffolded, upstream linked for future updates
- ✅ PC emulator compiles, 54/54 host tests pass
- ✅ Brazilian signature table researched and IEEE-verified
- 🔜 BR signatures wired into the detection table
- 🔜 Texugo / matrix theme and the Portuguese/English toggle
- 🔜 BR_902 LoRa profile
- 🔜 On-hardware verification on the CYD

---

## Build

Install [PlatformIO](https://platformio.org/), then:

```sh
git clone https://github.com/eduardonk9999/HoneyBadgerWatch
cd HoneyBadgerWatch
pio run -t upload
```

The default target is the 2.8" CYD (ESP32-2432S028R). Other boards each have
their own `[env:...]` in `platformio.ini`. A beginner-friendly walkthrough
lives in [docs/BUILD.md](docs/BUILD.md).

### Run it on your PC (no hardware)

The real UI code compiles natively — no board, no PlatformIO needed:

```sh
cd sim && make -j8      # builds ./squachsim
cd test && make         # compiles and runs the 54 host tests
```

---

## Credits and license

- **HoneyBadgerWatch** is a fork of **[SquachWatch-CYD](https://github.com/skizzophrenic/SquachWatch-CYD)**
  by **skizzophrenic** — the engine, the boards and the emulator are their work.
  Thank you.
- **Texugo** mascot pixel art: by the HoneyBadgerWatch project.
- Licensed under the **GNU General Public License v3.0**, same as upstream —
  see [LICENSE](LICENSE). A fork of GPLv3 software stays GPLv3.
