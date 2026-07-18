# Battery Charger Lab

An educational C++ project for learning embedded software design patterns.

This project simulates a simple battery charger and gradually introduces concepts commonly used in embedded systems:

- State machines
- Non-blocking timers
- Entry and exit actions
- Event-driven design
- Test harnesses
- Callbacks and lambdas
- Modern C++ techniques
- Unit testing
- CAN bus simulation (planned)

The emphasis is not on building the fastest charger simulation, but on learning how professional embedded software is structured.

---

## Project Goals

Rather than jumping directly into complex embedded applications, this project builds a realistic system one concept at a time.

Each feature should introduce one new idea while keeping the rest of the project understandable.

---

## Current Features

- Battery class
- Battery state machine
- Interactive CLI test harness
- WSL/Linux build using Make
- Modern C++20

---

## Planned Roadmap

### Phase 1 - Battery

- [x] Battery object
- [x] Basic battery state machine
- [x] Interactive CLI
- [ ] Transition helper
- [ ] Entry actions
- [ ] Exit actions
- [ ] Non-blocking timers
- [ ] Charging simulation

### Phase 2 - Charger

- [ ] Charger class
- [ ] Three charging slots
- [ ] Slot occupancy detection
- [ ] Multiple batteries

### Phase 3 - Events

- [ ] Event callbacks
- [ ] Lambdas
- [ ] Observer pattern

### Phase 4 - Communications

- [ ] Virtual CAN interface (vCAN)
- [ ] Charger telemetry
- [ ] Battery status messages

---

## Building

```bash
make
```

Run the test harness:

```bash
make run
```

Clean:

```bash
make clean
```

---

## Why this project?

The best way to learn embedded software is to build systems that resemble real products.

This repository intentionally grows slowly so that each new concept can be understood before introducing the next.