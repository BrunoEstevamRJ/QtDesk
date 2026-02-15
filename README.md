# QtDesk — Task Manager

A desktop Task Manager application built with **C++17** and **Qt6 Widgets**, featuring **SQLite persistence**, **REST API integration**, and **unit tests**.

> Built and tested on Linux.

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

##  Features

--[ Create tasks with:
   -[ Title
   -[ Description
   -[ Priority
--[ Mark tasks as completed
--[ Filter tasks:
   -[ All
   -[ Pending
   -[ Completed
--[ Search tasks by title
--[ Local persistence using **SQLite**
--[ Fetch a "Quote of the Day" from a public REST API (JSON)
--[ Clean project structure (UI / Core / DB / Net)
--[ Unit tests using **QtTest**

---

##  Tech Stack

--[ **C++17**
--[ **Qt 6 (Widgets, Network, SQL)**
--[ **SQLite**
--[ **CMake**
--[ **QtTest**
--[ **Linux**
--[ **Git**

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

## 📸 Screenshots

> Coming soon.

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

##  Project Structure

QtDesk/
├── CMakeLists.txt
├── README.md
├── src/
│ ├── main.cpp
│ ├── ui/
│ ├── core/
│ ├── db/
│ └── net/
└── tests/




>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

##  Build (Linux)

### Dependencies (Arch Linux)

```bash
sudo pacman -S --needed \
  base-devel cmake git \
  qt6-base qt6-tools qt6-svg \
  qt6-networkauth qt6-declarative \
  qt6-multimedia qt6-5compat \
  qtcreator
```

Build Steps

git clone https://github.com/BrunoEstevamRJ/QtDesk.git
cd QtDesk

cmake -S . -B build
cmake --build build -j

./build/QtDesk


  Running Tests

cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure


  Roadmap

Better UI layout and icons

Task edit feature

Export tasks to JSON

Import tasks from JSON

Dark mode support

QML version (future)


   Why this project?

This project was built to practice and demonstrate:

Modern C++ with clean OOP design

Qt6 Widgets development

Database persistence with QtSql

REST API integration with QtNetwork

Unit testing with QtTest

A real-world style project structure for junior roles

  License

MIT (or choose your preferred license).
