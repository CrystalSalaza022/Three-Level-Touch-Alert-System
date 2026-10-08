# Three-Level Touch Alert System

🔗 **Open full project in Velxio:**
👉 [Click Here — Open in Velxio](https://velxio.dev/crystaljanesalazar33/hci-project-1)

## Features
- 🟢 **Green**: 2 quick beeps, LED turns off when switching
- 🟡 **Yellow**: 2 medium beeps, LED turns off when switching
- 🔴 **Red**: 3 alert beeps, LED **STAYS ON** as a persistent reminder

## Components & Pinout
| Component | Pin |
|---|---|
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |
| Green Touch Sensor | D2 |
| Yellow Touch Sensor | D3 |
| Red Touch Sensor | D4 |
| Arduino Nano / Uno | — |
| 3 × 220Ω Resistors | — |

## How It Works
- Each sensor beeps **only once** when pressed
- Red LED stays ON even after releasing — press Green/Yellow to turn it off
- Runs automatically when powered on
