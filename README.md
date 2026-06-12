<div align="center">

# 🏏 Cricbuzz Management System

A console-based **Cricket Match Management System** built in **C++** to demonstrate the
core principles of **Object-Oriented Programming** — Encapsulation, Inheritance,
Polymorphism, and Abstraction.

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?logo=windows&logoColor=white)](#-getting-started)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

</div>

---

## 📖 Overview

Cricbuzz Management System is an admin-driven console application that lets you set up a
cricket match between two teams, load their squads from data files, manage players
(search / update), and conduct a simulated match that updates rankings based on the
result. It was built for the **Object-Oriented Programming** course and showcases a clean,
class-based design with full **CRUD** operations over player and team data.

---

## ✨ Features

- 🔐 **Admin login** — credential-protected entry point.
- 🆚 **Match setup** — choose two of four available teams (Pakistan, India, England, New Zealand).
- 📥 **Data loading** — team and player data are read in from text files.
- 👤 **Player CRUD** — add, search, and update players within a team.
- 📊 **Match details** — venue, date, type (ODI / T20 / Test), tournament, umpires, commentators.
- 🏆 **Match simulation** — conducts the match and updates team/player rankings on the result.

---

## 🧠 OOP Concepts Demonstrated

| Concept | Where it lives |
| --- | --- |
| **Abstraction** | `Player_Class` is an abstract base with pure-virtual operations ([src/Player.h](src/Player.h)) |
| **Inheritance** | `Team` inherits from `Player_Class` ([src/Team.h](src/Team.h)) |
| **Polymorphism** | `addPlayer` / `searchPlayer` / `updatePlayer` overridden in `Team` ([src/Team.cpp](src/Team.cpp)) |
| **Encapsulation** | Private data members exposed through getters/setters across every class |
| **Composition** | `Match` is composed of `Team` and `Date` objects ([src/Match.h](src/Match.h)) |

---

## 🗂️ Project Structure

```
Cricbuzz-Management-System-OOP/
├── src/                      # Source code
│   ├── Main.cpp              # Entry point, menus & app flow
│   ├── Date.h / Date.cpp     # Date value type
│   ├── Player.h / Player.cpp # Abstract Player_Class (base)
│   ├── Team.h / Team.cpp     # Team (derived from Player_Class)
│   └── Match.h / Match.cpp   # Match orchestration & simulation
├── data/
│   ├── teams/                # Team metadata (one file per team)
│   │   ├── Pakistan.txt
│   │   ├── India.txt
│   │   ├── England.txt
│   │   └── Newzeland.txt
│   └── players/              # Squad rosters (one file per team slot)
│       ├── Players Team 01.txt
│       ├── Players Team 02.txt
│       ├── Players Team 03.txt
│       └── Players Team 04.txt
├── PROJECT OOP.sln           # Visual Studio solution
├── PROJECT OOP.vcxproj       # Visual Studio project
├── LICENSE
└── README.md
```

---

## 🏛️ Class Architecture

```
        ┌────────────────────┐
        │   Player_Class     │  (abstract base)
        │  + addPlayer()  =0 │
        │  + searchPlayer()=0│
        │  + updatePlayer()=0│
        └─────────▲──────────┘
                  │ inherits
        ┌─────────┴──────────┐        ┌──────────┐
        │       Team         │        │   Date   │
        │  (concrete squad)  │        └────▲─────┘
        └─────────▲──────────┘             │
                  │ used by                │ used by
                  └───────────┬────────────┘
                      ┌───────┴────────┐
                      │     Match      │  (composes 2 Teams + a Date)
                      └────────────────┘
```

---

## 🚀 Getting Started

> ⚠️ **Windows only.** The app uses Windows console calls (`system("cls")`, `system("pause")`),
> so it is intended to be built and run with **Visual Studio on Windows**.

### Prerequisites
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload.

### Build & Run
```bash
# 1. Clone the repository
git clone https://github.com/Saadnadeem07/Cricbuzz-Management-System-OOP.git
cd Cricbuzz-Management-System-OOP
```
2. Open **`PROJECT OOP.sln`** in Visual Studio.
3. Press **F5** (Debug) or **Ctrl + F5** (Run without debugging).

The project's working directory is set to the repository root, so the relative
`data/` paths load correctly out of the box.

---

## 🔑 Login Credentials

| Field | Value |
| --- | --- |
| **Username** | `Admin` |
| **Password** | `M123` |

---

## 🕹️ Usage

1. **Log in** with the admin credentials above.
2. From the **Main Menu**, choose **Enter Match Details**.
3. In the **Match Menu**:
   - **Set Match Details** → venue, date, type, tournament, officials.
   - **Select Teams** → pick two different teams (1–4).
   - **Upload Teams Data** / **Upload Players Data** → load squads from `data/`.
   - **Display / Search / Update Players** → manage rosters.
4. Return to the Main Menu and choose **Conduct Match** to simulate the result.

---

## 📸 Screenshots

| Login Screen | Dashboard |
| --- | --- |
| ![Login](https://github.com/Saadnadeem07/Cricbuzz-Management-System-OOP/assets/112171181/ebf93872-3a87-4bfa-b5a0-6d782d132b04) | ![Dashboard](https://github.com/Saadnadeem07/Cricbuzz-Management-System-OOP/assets/112171181/499b6696-b5d0-41d0-ae8a-8731f7d8a345) |

---

## 👨‍💻 Author

**Muhammad Saad Nadeem**

[![GitHub](https://img.shields.io/badge/GitHub-Saadnadeem07-181717?logo=github&logoColor=white)](https://github.com/Saadnadeem07)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
