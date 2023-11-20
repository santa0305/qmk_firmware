# helix custom
helix custom
this firmware is folked from helix


## Usage
### Build
1. **modify keymap.c**
2. **bulid(with docker)**  
    it's need to install docker.  

    run command `util/docker_build.sh {PATH_TO_KEYBOARD_FOLDER}:{KEYMAP_FOLDER_NAME}`  
    for example `util/docker_build.sh helix_custom/rev3_5rows:via`  
    
    if sccuceed, '* The firmware size is fine' is displaied in stdout.
    and compiled file is placed in .build folder.

3. **flash firmware(with Pro Micro Web Updater)**  
    go to pro micro web updater site `https://sekigon-gonnoc.github.io/promicro-web-updater/index.html`  
    press select file button to read compiled file at above.
    
    below sequence is done each side keyboard.  
    1. **reset pro micro**  
    connect GND and REST to enter boot mode.  
    Alternatively, press reset button if your keyboard has it.  
    2. **press flash button**  
    if succeed, last line displayed is '......Verify OK.'

### Macro setting
1. **define custom keycode**  
    define custom keycode at line28 in keymap.c  
    `enum custom_keycodes {};`

2. **place key code into keymap**  
    place custom keycode into keymap when define keymap at line40 in keymap.c.  
    `const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {}`  

3. **define marco at press custom keycode**  
    define macro function at line140 in keymap.c  
    `bool process_record_user(uint16_t keycode, keyrecord_t *record) {}`


## Settings
### Macro for username, password, email address
- keycode for username is USER
- keycode for password is PASS

## TODO
### Macro
- macro for email address  
    there are something conflict when define macro for email address in process_record_user.  