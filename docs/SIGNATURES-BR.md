# HoneyBadgerWatch — assinaturas BR (OUI)

> Metodologia: toda OUI abaixo foi lida da base oficial **IEEE MA-L**
> (`standards-oui.ieee.org/oui/oui.csv`, baixada em 2026-10-18), não copiada de
> outro detector. Regra de confiança (mesma do SquachWatch):
> **HIGH** = bloco registrado ao próprio fabricante do equipamento de vigilância;
> **MED** = registrado ao fabricante, mas a marca também faz muita coisa que não
> é câmera (roteador, ONT, interfone); **LOW** = bloco de fabricante de
> chip/módulo genérico, compartilhado com meio mundo.
>
> Ordem = prioridade de match (vendors específicos antes de genéricos).

## Incluídas

| Vendor | Tipo | Conf. | Nº OUIs | Observação |
|---|---|---|---|---|
| Pumatronix | ALPR | HIGH | 1 | ALPR/OCR de trânsito (ITSCAM), Curitiba. Só faz isso → HIGH |
| Control iD | ACCESS* | HIGH | 1 | Reconhecimento facial / catraca (iDFace), BR. Só biometria/acesso |
| Grupo Digicon | ACCESS* | MED | 1 | Pedágio, catraca, controle de acesso (BR). Faz vários produtos → MED |
| Intelbras | CAMERA | MED | 18 | Gigante BR. É Intelbras de fato, mas também faz roteador/ONT/interfone → MED |
| Hikvision | CAMERA | HIGH | 84 | Quase só vigilância. Muralha/Smart Sampa usam |
| Dahua | CAMERA | HIGH | ~33 | Idem Hikvision |
| Ezviz | CAMERA | HIGH | 15 | Marca consumer da Hikvision, comum em casa BR |
| Axis | CAMERA | HIGH | 4 | Câmeras IP corporativas |
| Avigilon | CAMERA | HIGH | 1 | Vigilância (grupo Motorola) |
| Verkada | CAMERA | HIGH | 1 | Vigilância em nuvem |
| Verint (Loronix) | CAMERA | MED | 2 | Vídeo/analytics; também telecom → MED |
| Tuya | CAMERA | LOW | 42 | Plataforma white-label (câmera, plug, lâmpada). Muitas marcas BR usam → LOW |
| Positivo | CAMERA | LOW | 3 | Consumer BR; maioria não é câmera → LOW |
| Multilaser | CAMERA | LOW | 1 | Consumer BR → LOW |

\* `ACCESS` = tipo novo proposto (controle de acesso / reconhecimento facial).
Se não quiser novo tipo, Control iD/Digicon podem entrar como `CAMERA` MED.

## Excluídas (armadilhas verificadas — NÃO usar)

| Candidato | Por quê |
|---|---|
| Splice (radar BR) | `00:07:D9` no IEEE é **SpliceCom** (VoIP, Reino Unido). Nada a ver |
| Perkons | Sem bloco IEEE registrado (radar/pardal) — não dá p/ assinar por OUI |
| Radioenge / JFL / Giga Security / Henry | Sem bloco IEEE próprio |
| Greatek (`F8:7F:A5`) | Rede/PON BR, não vigilância |
| "GENETEC Corporation" (`00:0A:B1`) | Empresa japonesa, ≠ Genetec Inc/AutoVu (`00:BF:15`,`0C:BF:15`) |
| Prama Hikvision India | JV da Índia; fora p/ não alargar demais (ficam só os blocos Hangzhou) |

## SSID / BLE (a capturar no hardware)

Não há fonte pública confiável de SSID/UUID BLE desses equipamentos BR, e
**chutar vira falso positivo**. Ficam como TODO p/ captura em campo:
Intelbras (SSID de setup dos app-cams / interfones), Control iD e Digicon
(BLE de provisionamento das catracas). Registrar com `scan` real antes de virar
assinatura.

## LoRa — faixa BR (config, não é OUI)

Não é assinatura: é frequência. Meshtastic no Brasil usa a região **BR_902**
(902–907,5 e 915–928 MHz, ISM liberada pela ANATEL). O SquachWatch escolhe
915/868 MHz pelo fuso; precisamos de um **perfil BR_902** explícito.

---

## Apêndice — trecho C++ pronto (formato kOuiTable)

```cpp
    // ================= Assinaturas BR (IEEE MA-L, 2026-10-18) =================
    // ---- ALPR brasileiro ----
    {{0xF8, 0xD4, 0x62}, "ALPR-Puma", DetectionType::ALPR, Confidence::HIGH_CONF},
    // ---- Controle de acesso / facial (BR) ----
    {{0xFC, 0x52, 0xCE}, "ControlID", DetectionType::ACCESS, Confidence::HIGH_CONF},
    {{0x4C, 0x8B, 0x55}, "Digicon", DetectionType::ACCESS, Confidence::MED_CONF},
    // ---- Intelbras (MED: tambem faz roteador/ONT) ----
    {{0x58, 0x10, 0x8C}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x98, 0x2A, 0x0A}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x80, 0x8F, 0xE8}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x18, 0x0D, 0x2C}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x80, 0x85, 0x44}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0xAC, 0x1E, 0xA9}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x54, 0xBA, 0xD9}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0xCC, 0x81, 0x30}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0xB8, 0x7E, 0xE5}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0xD8, 0x77, 0x8B}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x00, 0x1A, 0x3F}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x98, 0xE5, 0x5B}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0xD8, 0x36, 0x5F}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x48, 0x51, 0xCF}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x44, 0x3B, 0x32}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x24, 0xFD, 0x0D}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x30, 0xE1, 0xF1}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x54, 0x6C, 0xAC}, "Intelbras", DetectionType::CAMERA, Confidence::MED_CONF},
    // ---- Cameras de vigilancia (reforco BR) ----
    {{0x64, 0xF2, 0xFB}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x94, 0xEC, 0x13}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xEC, 0x97, 0xE0}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xF4, 0x70, 0x18}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xFC, 0x24, 0x22}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x38, 0xF2, 0x5D}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x78, 0xC1, 0xAE}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x58, 0x8F, 0xCF}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x78, 0xA6, 0xA0}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x54, 0xD6, 0x0D}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x20, 0xBB, 0xBC}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x64, 0x24, 0x4D}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x0C, 0xA6, 0x4C}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x34, 0xC6, 0xDD}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xAC, 0x1C, 0x26}, "Ezviz", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x70, 0x1A, 0xD5}, "Avigilon", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0xA7, 0x00}, "Verkada", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xB8, 0xA4, 0x4F}, "Axis", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x00, 0x40, 0x8C}, "Axis", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE8, 0x27, 0x25}, "Axis", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xAC, 0xCC, 0x8E}, "Axis", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x00, 0x0D, 0x40}, "Verint", DetectionType::CAMERA, Confidence::MED_CONF},
    {{0x00, 0x07, 0x9A}, "Verint", DetectionType::CAMERA, Confidence::MED_CONF},
    // ---- Genericos / white-label (LOW) ----
    {{0x1C, 0x90, 0xFF}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xFC, 0x3C, 0xD7}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xE4, 0xAE, 0xE4}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xFC, 0x67, 0x1F}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xCC, 0x8C, 0xBF}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x38, 0x1F, 0x8D}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x10, 0xD5, 0x61}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x84, 0xE3, 0x42}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD4, 0xA6, 0x51}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xB8, 0x06, 0x0D}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x38, 0x2C, 0xE5}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x38, 0xA5, 0xC9}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xF8, 0x17, 0x2D}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD8, 0xC8, 0x0C}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x00, 0x33, 0x7A}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD8, 0xFC, 0x92}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x2C, 0xB4, 0x71}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xC4, 0x82, 0xE1}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x10, 0x5A, 0x17}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xC0, 0xF8, 0x53}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x3C, 0x0B, 0x59}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xBC, 0x35, 0x1E}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x20, 0xF1, 0xB2}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x30, 0x48, 0x7D}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD0, 0x82, 0xEB}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD0, 0x82, 0xE8}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x18, 0xDE, 0x50}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xA0, 0x92, 0x08}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x7C, 0xF6, 0x66}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x70, 0x89, 0x76}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x18, 0x69, 0xD8}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD8, 0xD6, 0x68}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x80, 0x64, 0x7C}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xA8, 0x80, 0x55}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x50, 0x8B, 0xB9}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD8, 0x1F, 0x12}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x50, 0x8A, 0x06}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x68, 0x57, 0x2D}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x4C, 0xA9, 0x19}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xD0, 0x32, 0xE7}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xAC, 0xF8, 0x78}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xA8, 0xDD, 0xBC}, "Tuya", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x44, 0x0B, 0xAB}, "Positivo", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0xDC, 0x35, 0xF1}, "Positivo", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x00, 0x9E, 0xEE}, "Positivo", DetectionType::CAMERA, Confidence::LOW_CONF},
    {{0x74, 0x58, 0x89}, "Multilaser", DetectionType::CAMERA, Confidence::LOW_CONF},
    // ---- Hikvision (lista longa; Hangzhou apenas) ----
    {{0x0C, 0x75, 0xD2}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x54, 0x8C, 0x81}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x24, 0x48, 0x45}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xEC, 0xC8, 0x9C}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x8C, 0xE7, 0x48}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x24, 0x28, 0xFD}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xAC, 0xB9, 0x2F}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xD4, 0xE8, 0x53}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x24, 0x0F, 0x9B}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC0, 0x6D, 0xED}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x24, 0x32, 0xAE}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0xBA, 0xAD}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0xCA, 0x3C}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xDC, 0x07, 0xF8}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x64, 0xDB, 0x8B}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x94, 0xE1, 0xAC}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x58, 0x03, 0xFB}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x44, 0x47, 0xCC}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x98, 0xDF, 0x82}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC0, 0x56, 0xE3}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xBC, 0xAD, 0x28}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x80, 0xF5, 0xAE}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA4, 0x29, 0x02}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x84, 0x94, 0x59}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x00, 0xBC, 0x99}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x04, 0xEE, 0xCD}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x18, 0x80, 0x25}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x08, 0xCC, 0x81}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA4, 0x14, 0x37}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xF8, 0x4D, 0xFC}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x84, 0x9A, 0x40}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC0, 0x51, 0x7E}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x2C, 0xA5, 0x9C}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x40, 0xAC, 0xBF}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x98, 0xF1, 0x12}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x98, 0x9D, 0xE5}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x3C, 0x1B, 0xF8}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0x1F, 0x86}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xCC, 0x13, 0xF3}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xB0, 0xFF, 0x0D}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x28, 0x57, 0xBE}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x58, 0x50, 0xED}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x10, 0x12, 0xFB}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0xF5, 0xDC}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x98, 0x8B, 0x0A}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x80, 0x7C, 0x62}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xBC, 0x9B, 0x5E}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x18, 0x68, 0xCB}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xBC, 0xBA, 0xC2}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xAC, 0xCB, 0x51}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x80, 0xBE, 0xAF}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x04, 0x03, 0x12}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xEC, 0xA9, 0x71}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE4, 0xD5, 0x8B}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC8, 0xA7, 0x02}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA4, 0x4B, 0xD9}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x88, 0xDE, 0x39}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x08, 0x3B, 0xC1}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x48, 0x78, 0x5B}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0x62, 0xDF}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x44, 0x19, 0xB6}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xBC, 0x5E, 0x33}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xFC, 0x9F, 0xFD}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE8, 0xA0, 0xED}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x5C, 0x34, 0x5B}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0xBD, 0x8F}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x34, 0x09, 0x62}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA4, 0xA4, 0x59}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x80, 0x48, 0x9F}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x8C, 0x22, 0xD2}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x40, 0xB5, 0x70}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0xDF, 0x13}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xDC, 0xD2, 0x6A}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x50, 0xE5, 0x38}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA0, 0xFF, 0x0C}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x08, 0x54, 0x11}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x74, 0x3F, 0xC2}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA4, 0xD5, 0xC2}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC4, 0x2F, 0x90}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x54, 0xC4, 0x15}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xB4, 0xA3, 0x82}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x68, 0x6D, 0xBC}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x08, 0xA1, 0x89}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x44, 0xA6, 0x42}, "Hikvision", DetectionType::CAMERA, Confidence::HIGH_CONF},
    // ---- Dahua ----
    {{0x74, 0xC9, 0x29}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x6C, 0x1C, 0x71}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x08, 0xED, 0xED}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0x2E, 0xFE}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x40, 0x7A, 0xA4}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x5C, 0xF5, 0x1A}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xFC, 0x5F, 0x49}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x24, 0x52, 0x6A}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x90, 0x02, 0xA9}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE0, 0x50, 0x8B}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC4, 0xAA, 0xC4}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA0, 0xBD, 0x1D}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x9C, 0x14, 0x63}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xBC, 0x32, 0x5F}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x38, 0xAF, 0x29}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xF8, 0xCE, 0x07}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0x99, 0xE8}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x20, 0x2C, 0x05}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x8C, 0xE9, 0xB4}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x14, 0xA7, 0x8B}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x4C, 0x11, 0xBF}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x64, 0xFD, 0x29}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xA8, 0xCA, 0x87}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x98, 0xF9, 0xCC}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xD4, 0x43, 0x0E}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xF4, 0xB1, 0xC2}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x3C, 0xE3, 0x6B}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xFC, 0xB6, 0x9D}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xE4, 0x24, 0x6C}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xC0, 0x39, 0x5A}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0xB4, 0x4C, 0x3B}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x3C, 0xEF, 0x8C}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
    {{0x30, 0xDD, 0xAA}, "Dahua", DetectionType::CAMERA, Confidence::HIGH_CONF},
```
