# Final-Project_Security-System
Door Locker Security System
**Door Locker Security System Implementation**

**Specifications:**

1. Use two ATmega32 Microcontrollers with a frequency of 8MHz.
2. Implement a layered architecture model:
   - MCU1 (HMI_ECU): Human Machine Interface with 2x16 LCD and 4x4 keypad.
   - MCU2 (Control_ECU): Control unit with EEPROM, Buzzer, and DC-Motor.

**HMI_ECU (MCU1):**
1. Interaction with the user via keypad and display messages on LCD.
2. Connected to 2x16 LCD and 4x4 keypad.
3. Responsible for entering and confirming passwords.

**Control_ECU (MCU2):**
1. Processing and decision-making:
   - Password checking.
   - Door unlocking.
   - System alarm activation.
2. Connected to EEPROM, Buzzer, and DC-Motor.

**System Sequence:**

**Step 1: Create a System Password**
- LCD displays "Please Enter Password".
- User enters a 5-digit password with * displayed.
- User confirms the same password.
- If passwords match, save in EEPROM and proceed; else, repeat step.

**Step 2: Main Options**
- LCD continuously displays main system options.

**Step 3: Open Door**
- LCD displays "Please Enter Password".
- User enters password and presses enter.
- Control_ECU verifies password.
- If passwords match:
  - Rotate motor CW for 15 seconds.
  - Display "Door is Unlocking".
  - Pause motor for 3 seconds.
  - Rotate motor ACW for 15 seconds.
  - Display "Door is Locking".

**Step 4: Change Password**
- LCD displays "Please Enter Password".
- User enters password and presses enter.
- Control_ECU verifies password.
- If passwords match, repeat Step 1.

**Step 5: Password Verification Loop**
- If passwords do not match in Step 3 or Step 4:
  - Ask user for password again.
  - If passwords match, proceed with unlocking or changing password.
  - If passwords match after third attempt, activate buzzer and lock system for 1 minute.

**GPIO Driver Requirements:**
- Use existing GPIO driver implemented in the course.

**LCD Driver Requirements:**
- Use 2x16 LCD.
- Use existing LCD driver implemented in the course (8-bits or 4-bits data mode).

**Keypad Driver Requirements:**
- Use 4x4 Keypad.
- Connect Keypad pins to MCU1.

**DC_Motor Driver Requirements:**
- Use existing DC_Motor driver implemented in the fan controller project.
- Motor runs with maximum speed using Timer0 PWM.
- Connect Motor pins to MCU2.

**EEPROM Driver Requirements:**
- Use existing external EEPROM driver controlled by I2C.
- Connect EEPROM to MCU2.

**I2C Driver Requirements:**
- Use existing I2C driver implemented in the course.
- Use I2C for communication between MCU2 and external EEPROM.

**UART Driver Requirements:**
- Use existing UART driver implemented in the course.
- Use UART for communication between MCU1 and MCU2.

**Timer Driver Requirements:**
- Use existing Timer driver implemented in the course.
- Timer1 driver to count displaying messages time on LCD while opening/closing the door.
- Timer1 driver to control motor time in MCU2.

**Buzzer Driver Requirements:**
- Implement a full Buzzer driver.
- Connect Buzzer to MCU2.
- Use static configurations to choose Buzzer pin.
- Driver functions: Buzzer_init, Buzzer_on, Buzzer_off.
