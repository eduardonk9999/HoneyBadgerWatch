# HoneyBadgerWatch

> Detector de dispositivos de vigilância para o ESP32 "Cheap Yellow Display" — feito pro Brasil, destemido que nem o texugo.

<p align="center">
  <img src="docs/texugo.png" width="200" alt="Texugo, o mascote texugo-do-mel, em pixel art">
</p>

<p align="center">
  <b>🇺🇸 <a href="README.md">Read in English</a></b>
</p>

O HoneyBadgerWatch é um scanner de mão que fareja WiFi e Bluetooth atrás das
assinaturas de equipamento de vigilância — câmeras de placa, body cams,
chupa-cabras, rastreadores escondidos, drones — e grita quando acha um. Roda
**sozinho numa placa de ~R$80**: sem PC, sem app, é só plugar no USB.

A sacada é a atitude. O mascote é o **Texugo**, um texugo-do-mel — o bicho que
não tá nem aí, que encara qualquer coisa — num **terminal verde matrix** com
uma dose de **internet raiz anos 2000**. O nome é um trocadilho com os dois
humores dele: **"do mel, ou mal"**.

> **O texugo não tá nem aí.**

---

## Isto é um fork — crédito a quem merece

O HoneyBadgerWatch é um fork do **[SquachWatch-CYD](https://github.com/skizzophrenic/SquachWatch-CYD)**,
do **skizzophrenic** — um projeto open-source excelente (GPLv3) que faz todo o
trabalho pesado de rádio e de interface. A gente está nos ombros dele. Todo o
motor de detecção, o atualizador OTA, o suporte às placas, o emulador de PC e a
suíte de testes vêm de lá, sem mudança no núcleo.

**O que o HoneyBadgerWatch acrescenta** é um olhar brasileiro: fabricantes de
vigilância locais, a faixa de LoRa do Brasil, interface em português/inglês, e
uma identidade própria. Se você é de fora do Brasil, talvez o projeto original
se encaixe melhor — vai lá dar uma estrela nele.

---

## O que ele detecta

Herdado do motor original — câmeras (Flock, Axon, câmeras IP genéricas, Ring),
rastreadores (AirTag, Tile, SmartTag, Google Find My), drones (Remote ID,
decodificado), leitores de placa, óculos com câmera, chupa-cabras Bluetooth,
sensores de tiro, e ataques WiFi ao vivo (**deauth floods**, **evil twins**),
além de ferramental de pentest (Flipper Zero, Pwnagotchi, WiFi Pineapple).

Cada assinatura carrega um **grau de confiança** honesto — High só quando o
prefixo de hardware é registrado ao próprio fabricante na base IEEE, Low quando
é um bloco de fabricante de chip compartilhado com meio mundo.

### 🇧🇷 Os acréscimos brasileiros

Porque os projetos focados nos EUA não enxergam o que de fato te vigia aqui:

| O quê | Fabricantes / detalhe |
|---|---|
| **ALPR / trânsito** | Pumatronix (ITSCAM) |
| **Facial / controle de acesso** | Control iD, Grupo Digicon |
| **Câmeras (locais + onipresentes)** | Intelbras, mais reforço de Hikvision / Dahua / Ezviz / Axis / Verkada / Avigilon |
| **Monitoramento público** | Smart Sampa, Muralha (rodam nos fabricantes de câmera acima) |
| **LoRa** | Faixa brasileira **BR_902** (902–907,5 / 915–928 MHz, ISM da ANATEL) |

Todas as OUIs foram lidas direto da **base oficial IEEE MA-L**, não copiadas de
outro detector — e as falsas correspondências verificadas estão documentadas e
de fora (ex.: `00:07:D9` é a SpliceCom, do Reino Unido, e **não** a Splice
brasileira de radar). A tabela completa está em
**[docs/SIGNATURES-BR.md](docs/SIGNATURES-BR.md)**.

---

## Idioma

A interface vem em **português e inglês** (troca nas configurações), pra mesma
peça fazer sentido pra criador e usuário dos dois países. **Os termos técnicos
ficam em inglês nas duas línguas** — nomes de tipo de detecção (`FLOCK`,
`DEAUTH`, `AIRTAG`), siglas (`MAC`, `RSSI`, `OUI`, `SSID`, `LoRa`) e verbos de
firmware (`flash`, `scan`) — pra tela de LOG e de alerta serem idênticas em
qualquer lugar.

---

## Status

> 🚧 **Começando.** O fork está scaffoldado e o núcleo herdado compila e passa
> nos testes. O rebrand brasileiro está em andamento.

- ✅ Fork scaffoldado, upstream linkado pra puxar atualizações
- ✅ Emulador de PC compila, 54/54 testes passam
- ✅ Tabela de assinaturas BR pesquisada e verificada na IEEE
- 🔜 Assinaturas BR ligadas na tabela de detecção
- 🔜 Tema texugo / matrix e o toggle português/inglês
- 🔜 Perfil de LoRa BR_902
- 🔜 Verificação no hardware real (CYD)

---

## Build

Instale o [PlatformIO](https://platformio.org/) e:

```sh
git clone https://github.com/eduardonk9999/HoneyBadgerWatch
cd HoneyBadgerWatch
pio run -t upload
```

O alvo padrão é a CYD 2.8" (ESP32-2432S028R). Cada outra placa tem seu próprio
`[env:...]` no `platformio.ini`. Um guia passo a passo está em
[docs/BUILD.md](docs/BUILD.md).

### Rode no PC (sem hardware)

O código real da interface compila nativamente — sem placa, sem PlatformIO:

```sh
cd sim && make -j8      # gera ./squachsim
cd test && make         # compila e roda os 54 testes
```

---

## Créditos e licença

- O **HoneyBadgerWatch** é um fork do **[SquachWatch-CYD](https://github.com/skizzophrenic/SquachWatch-CYD)**,
  do **skizzophrenic** — o motor, as placas e o emulador são trabalho dele.
  Valeu!
- Pixel art do mascote **Texugo**: pelo projeto HoneyBadgerWatch.
- Licenciado sob a **GNU General Public License v3.0**, igual ao original —
  veja [LICENSE](LICENSE). Fork de software GPLv3 continua GPLv3.
