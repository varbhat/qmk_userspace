# *qmk_userspace* ⌨️ 🖲️
## 🔱 My [QMK](https://qmk.fm) [Userspace](https://github.com/qmk/qmk_userspace) currently used for my [crkbd/corne](https://github.com/foostan/crkbd/tree/v3-final) and [adept/madromys](https://github.com/ploopyco/adept-trackball).

![QMK](https://img.shields.io/badge/qmk-%23000000.svg?logo=qmk)
![GitHub License](https://img.shields.io/github/license/varbhat/qmk_userspace)

## Features
- [Github Actions](https://github.com/features/actions) to build Firmware for my `corne` keyboard and `adept` trackball.
- Visualization of Keymaps using [Keymap-drawer](https://github.com/caksoylar/keymap-drawer). Note that the layer names are not present in the visualization. Look into [keymap.c](keyboards/crkbd/keymaps/vbt/keymap.c) for the correct information.

<details open>
<summary>Layout Visualization using <a href="https://github.com/caksoylar/keymap-drawer">keymap-drawer</a> (Appearance of Layout is Dark themed)</summary>

![crkbd_rev1_vbt_dark.png](https://github.com/varbhat/qmk_userspace/releases/latest/download/crkbd_rev1_vbt_dark.png?raw=true)

![ploopyco_madromys_rev1_001_vbt_dark.png](https://github.com/varbhat/qmk_userspace/releases/latest/download/ploopyco_madromys_rev1_001_vbt_dark.png?raw=true)

</details>

<details>
<summary>Layout Visualization using <a href="https://github.com/caksoylar/keymap-drawer">keymap-drawer</a> (Appearance of Layout is Light themed)</summary>

![crkbd_rev1_vbt_light.png](https://github.com/varbhat/qmk_userspace/releases/latest/download/crkbd_rev1_vbt_light.png?raw=true)


![ploopyco_madromys_rev1_001_vbt_light.png](https://github.com/varbhat/qmk_userspace/releases/latest/download/ploopyco_madromys_rev1_001_vbt_light.png?raw=true)

</details>

## Setup the QMK Workspace
- This Repository is a `QMK Userspace` Repository. Instructions listed [here](https://github.com/qmk/qmk_userspace) can be followed to setup `QMK Userspace`. Or follow the following:
    - Install `qmk` using `pipx` or your package manager.
    - Setup `qmk` using `qmk setup`
    - Clone this repository
    - In the cloned repository, execute `qmk config user.overlay_dir="$(realpath .)"`


## Features of my `corne` keymap
- `DVORAK` Layout (Alternating between the Hands is one of the main benefit of Dvorak)
- 5 Layers: `DVORAK`,`QWERTY`, `NUM`, `SYM`, `NAV`
- `VBUS` Detection using `GPIO19` for (My MCU is [Splinky](https://github.com/Bastardkb/Splinky). Using `VBUS` detection instead of USB Data channel detection, the keyboard can work without replugging and can be used to enter the BIOS)
- Vertically Aligned OLED Display/Indicator. It displays Layer Names, Modifier Status(Super,Ctrl,Alt,Shift), Lock Status(CAPS Lock, Num Lock, Scr Lock) and `corne` logo. Distracting/Animating elements such as `WPM` indicators, pets(luna/bongocat/etc.), Keyloggers are disabled and not supported.
- Utilizes Combos and One Shot Keys.
- No `via` or `vial` support. I don't want any security loopholes. Let this Repository be the source of truth and everytime you make the changes, you reflash the keyboard with the new firmware.
- `NUM` and `SYM` layer keys on the right thumb cluster will toggle to respective layers on double tap and will momentarily switch otherwise. It's achieved using `TAPPING_TOGGLE` feature of QMK (`TT`) set to 2.

<details>
<summary><a href="https://docs.qmk.fm/features/combo">Combo</a></summary>
 
`Escape` + `Backspace` => `DEL`

`Space` + `Enter` => Move to Base `Dvorak` Layer. Turns off all other layers

</details>
      

## Usage for `corne`
`.uf2` firmware for the `corne` is required. You can compile the `.uf2` firmware locally or can obtain the precompiled `.uf2` firmware (Compiled using Github Actions). Then, it needs to be flashed to the `corne`.

#### Github Actions
- Go to [Github Releases](https://github.com/varbhat/qmk_userspace/releases) and download the latest [.uf2](https://github.com/microsoft/uf2) file, or get here: [crkbd_rev1_vbt_promicro_rp2040.uf2](https://github.com/varbhat/qmk_userspace/releases/latest/download/crkbd_rev1_vbt_promicro_rp2040.uf2)

#### Local
- Setup the QMK Workspace.
- Compile the Firmware using `qmk compile --clean -kb crkbd -km vbt`
 
### Flashing the `corne`
- Disconnect TRRS/TRS cable between the `corne` splits.
- For both of `corne` splits, do:
   - Connect your `corne` split to the computer using `USB`.
   - Press spst switch (also called as reset switch) of the split two times consequently so that your [RP2040](https://www.raspberrypi.com/documentation/microcontrollers/rp2040.html) based MCU will go to `Bootloader` Mode.
   - You must see `Raspberry PI Boot Device` in the output of `lsusb`. It's also detected as Mass Storage Device.
   - Drag and Drop (`cp` or `copy`) the `.uf2` file to the `RP2040` Mass Storage Device.
   - After the firmware is copied, you will see that the MCU exits `Bootloader` mode and Mass Storage Device is no longer present. It means that the firmware is flashed!

## Features of my `adept` keymap
- `via` is disabled.
- Has 2 layers (which are mirrored copies of one another) which facilitates Ambidexterity.
- Combo to switch between `RIGHT_HAND` and `LEFT_HAND` layer (Press btn4 and btn5 together).
- Look into [keymap.c](keyboards/ploopyco/madromys/keymaps/vbt/keymap.c) for the more information.


<details>
<summary><a href="https://docs.qmk.fm/features/combo">Combo</a></summary>
 

`BTN4` + `BTN5` => Toggle `LEFT_HAND` layer on and off.

</details>
      

## Usage for `adept`
`.uf2` firmware for the `adept` is required. You can compile the `.uf2` firmware locally or can obtain the precompiled `.uf2` firmware (Compiled using Github Actions). Then, it needs to be flashed to the `adept`.

#### Github Actions
- Go to [Github Releases](https://github.com/varbhat/qmk_userspace/releases) and download the latest [.uf2](https://github.com/microsoft/uf2) file, or get here: [ploopyco_madromys_rev1_001_vbt.uf2](https://github.com/varbhat/qmk_userspace/releases/latest/download/ploopyco_madromys_rev1_001_vbt.uf2)

#### Local
- Setup the QMK Userspace.
- Compile the Firmware using `qmk compile --clean -kb ploopyco/madromys -km vbt`
 
### Flashing the `adept`
- Follow the official instructions: [Adept Trackball Wiki](https://github.com/ploopyco/adept-trackball/wiki/Appendix-D%3A-QMK-Firmware-Programming#putting-the-ploopy-device-into-bootloader-mode)

## License
[GPL-v2](LICENSE)
