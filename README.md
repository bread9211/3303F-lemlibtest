# Overview (components)
### Motors
The bot uses motors for three components: the drivetrain, intake, and the hang

**Drivetrain:**
- 66W (6 motors * 11W)
- brake mode:
  - COAST: during **driver control**
  - HOLD: during **autonomous**
- two pairs of four **3.25"** *newer* (not green) **omniwheels** (front & back)
- two pairs of four **3.25"** **traction wheels** (middle)

### (CURRENT) PID Constants
subject to change. at like. literally any time

#### Linear Controller:
- **P:** 9
- **I:** 0
- **D:** 7

- // 20 kP, 5 kD -> NOT FULLY TUNED YET (i.e. gotten to step 5 where oscillation can no longer be stopped) 

// 10, <5 -> NOT overshooting but oscillating
// 9, no D -> undershooting

// 10, 5 -> still overshooting

---

#### Angular Controller:
- **P:** 3
- **I:** 0
- **D:** 16

- // 2, 8
// 3, 16 -> NOT FULLY TUNED YET (i.e. gotten to step 5 where oscillation can no longer be stopped)

# Ports
### Drivetrain
- **Left Drivetrain...**
  - Front: -19
  - Middle: -18
  - Back: -20
  - **do note that the left motors are *all reversed!***
- **Right Drivetrain...**
  - Front: 11
  - Middle: 12
  - Back: 13


# Controls
### Drivetrain
- tank drive (left and right joysticks' y-axes)

### Hang
- hold **L2** -> *opens* hang
- hold **B** -> *closes* hang
- press **UP arrow** -> *ratchets* hang (**LOCKS IT IN PLACE**)

### Intake
- hold **R1** -> *intake*
- hold **R2** -> *outtake*

### Wings
- horizontal wings
  - press **L1** -> *toggles* wings
- vertical wings
  - press **LEFT arrow** -> *toggles* vertical wings


# Formatting
### Commenting
**make sure that most TODO comments are only placed in `main.h`!**

---

### Spacing
three spaces between...
- class / function definitions
- different sections of definitions

two spaces between...
- different "sections" of a block of code (w/in func)

one space between...
- different "subsections" of a related "section"
- parameters of a function call (where there are comments for the parameters!)
