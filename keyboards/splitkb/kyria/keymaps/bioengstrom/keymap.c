/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),


///*
// * Base Layer: QWERTY
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
// *                        |      |      | Enter|      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// */
//    [_QWERTY] = LAYOUT(
//     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
//     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
//     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
//                                ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
//    ),

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layers {
    _QWERTY_BIO = 0,
    _NAV_BIO,
    _SYM_BIO,
    _NUM_BIO
};


// Aliases for readability
#define QWERTY_BIO   DF(_QWERTY_BIO)

#define NAV_QUO     LT(_NAV_BIO, SE_QUOT)
#define NUM_DQU     LT(_NUM_BIO, SE_DQUO)


#define NAV_BIO  MO(_NAV_BIO)
#define SYM_BIO  MO(_SYM_BIO)
#define NUM_BIO  MO(_NUM_BIO)

//#define SFT_ESC  MT(KC_LSFT, KC_ESC)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Left home row
#define CTL_A  MT(MOD_LCTL, SE_A)
#define SFT_S  MT(MOD_LSFT, SE_S)
#define ALT_D  MT(MOD_LALT, SE_D)



// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY_BIO
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | "/NUM  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |A/Ctrl|S/Shft|D/LAlt|   F  |   G  |                              |   H  |   J  |   K  |   L  | '/Nav| "/NUM  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  ; | . :  | -  _ | +  ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LGUI | LAlt | Space| Enter|  | Del  | Bksp | AltGr| RGUI |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[_QWERTY_BIO] = LAYOUT(
 KC_TAB  , SE_Q ,  SE_W   ,  SE_E  ,   SE_R ,   SE_T ,                                        SE_Y,   SE_U ,  SE_I ,   SE_O ,  SE_P , NUM_DQU,
 KC_LSFT , CTL_A,  SFT_S  ,  ALT_D ,   SE_F ,   SE_G ,                                        SE_H,   SE_J ,  SE_K ,   SE_L ,NAV_QUO, NUM_DQU,
 CTL_ESC , SE_Z ,  SE_X   ,  SE_C  ,   SE_V ,   SE_B , _______, _______,     KC_APP ,_______, SE_N,   SE_M ,SE_COMM, SE_DOT ,SE_MINS, NUM_DQU,
                            _______, KC_LGUI, KC_LALT, KC_SPC , KC_ENT ,     KC_DEL ,KC_BSPC,SYM_BIO, KC_RGUI, SE_PLUS
),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgDn |  ←   |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV_BIO] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


 /*
  * SYMBOLS
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |  @   |  £   |  $   |  €   |                              |      |      |      |  /   |  \   |   |    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |  {   |  [   |  ]   |  }   |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |  <   |  (   |  )   |  >   |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_SYM_BIO] = LAYOUT(
       _______, _______ ,  SE_AT, SE_PND , SE_DLR, SE_EURO,                                      _______, _______, _______, SE_SLSH, SE_BSLS, SE_PIPE,
       _______, _______, _______, _______, _______, _______,                                     _______, SE_LCBR, SE_LBRC, SE_RBRC, SE_RCBR, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_LABK, SE_LPRN, SE_RPRN, SE_RABK, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

/*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |   1  |   2  |   3  |  4   |   5  |                              |  6   |   7  |   8  |   9  |   0  |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |  å   |   ä  |   ö  |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NUM_BIO] = LAYOUT(
       _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , _______,
       _______, _______, _______, _______, _______, _______,                                     _______, SE_ARNG, SE_ADIA, SE_ODIA, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
};


/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
/* 	Note for rendering images on Oled screens.
*	Screens are setup in horizontal rows, 8 pixels high, they render left to right.
*	Unless told otherwise they will keep going to the right until running out of space on that row and will then wrap down to the next row.
*	If you run over the end of the bottom row it will loop back to the start of the top row.
*	Using oled_set_cursor(X,Y) we can set position of where to start rendering.
*	X is the position from the left spaced in character spacing (default is 6px wide per character), starting at 0 for the start of the row.
*	Y is the position from the top row, starting at 0 for the top row.
*	128x32 size Oleds have 4 rows, 128px wide and 8px high, identified from row 0 being the top row and row 3 at the bottom.
*	They are 21.3 characters wide, with 0 being the left most and 20 being the start of the last character.
*	If you try render a 32px x 32px picture it will draw the first 32px wide, then the next 32px wide section next to it, not under it.
*	To correct for this the image needs to be broken up into segments, each segment being what is to be rendered on that line.
*	Breaking the image into segments is easy as each vertical row of 8px in the column is a byte. Represented in the image file as a hexidecimal value.
*	This translates to a binary digit rendered vertically in our Oled column http://cactus.io/resources/toolbox/decimal-binary-octal-hexadecimal-conversion
*	Data for each row of our Oled is then X amount of hexidecimal value's where X is how many pixels wide the image is we are trying to render.
*	Putting these chunks sequentially inside a const char allows us to pull them out easily.
*	Setup is <char_name>[<total number of chunks>][<how many pixels wide each chunk is>]
*	If rendering single image only then total number of chunks is simply how many lines, if animation is lines x images
*	Note, while logo_example[4][32] is 4 lines of image each 32px wide, when we call them back the counter starts at 0 and goes to 3, not 1 to 4
*	Once we have our image broken up we need to render it line by line, for our 32x32px example we want to
*	Set cursor to the desired X position on Y = 0 row, render the [0] chunk
*	Set cursor to the desired X position on Y = 1 row, render the [1] chunk
*	Set cursor to the desired X position on Y = 2 row, render the [2] chunk
*	Set cursor to the desired X position on Y = 3 row, render the [3] chunk
*	To avoid doing this manually, especially if rendering multiple images we can setup a loop we can feed the images into.
*
*	// Loop to create line by line rendering for Horizontal display
*	// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
*	void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
*	for (uint8_t i = 0; i < lines; i++){
*            oled_set_cursor(X_pos, Y_pos + i);
*			oled_write_raw_P(render_line[i + frame], px);
*		}
*	}
*
*	oled_render_image(4, 32, my_logo, 15, 0, 0, 0, 0);
* 	This would draw the my_logo image, 32x32px in size, on the far right of the screen.
*	Note : 128x32 screens only have 4 rows high, if you were try render at 15,1 as the first row of the image
*	would be on the second row of the screen and the last row would wrap around and be on the first row.
*   Note : The Frame offset is used to select different images in the array. Eg. Sit1 is 0,1,2 in the array and Sit2 is 3,4,5.
*	If we want to render Sit2 we offset the counter by 3 to get 3,4,5.
*/
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }


/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 50

/* advanced settings */
#define LUNA_FRAME_DURATION 230 // how long each frame lasts in ms
#define LUNA_SIZE 32 // number of bytes in array. This is how many pixels wide your image is. max is 1024 but would apply if line wrapping and not segmeting image and on 128x64 size screen, 512 is max on 128x32.

/* Setup Variables */
uint8_t current_frame = 0;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
int jump_height = 0;

// Loop to create line by line rendering for Horizontal display
// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
	void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
	for (uint8_t i = 0; i < lines; i++){
            oled_set_cursor(X_pos, Y_pos + i);
			oled_write_raw_P(render_line[i + frame], px);
		}
	}

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y, int LOGO_X, int LOGO_Y) {

	/* setup some variables & timers */
	static uint8_t prev_wpm = 0;
	static uint32_t tap_timer = 0; // WPM and mod triggered
	if (get_current_wpm() > prev_wpm || get_mods()) { tap_timer = timer_read32(); }
	prev_wpm = get_current_wpm();

	// Elapsed time between key presses
	uint32_t keystroke = timer_elapsed32(tap_timer);
	static uint16_t anim_timer = 0;

// 'QMK logo', 32x32px
    static const char PROGMEM qmk_logo[4][32] = {
		{0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xfe, 0xf0, 0x70, 0xf0, 0xfe, 0xf0, 0xf0,
		0xf0, 0x7e, 0xf0, 0xf0, 0xf0, 0xfe, 0xf0, 0x70, 0xf0, 0xfe, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x80},
		{0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x88},
		{0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xf1,
		0x80, 0x00, 0x80, 0xf1, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x88},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x07,
		0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x07, 0x07, 0x3f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00}
    };

    /* Sit - 32x24px */
    static const char PROGMEM sit[6][LUNA_SIZE] = {
        /* 'sit1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
		0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        /* 'sit2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
        0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Walk - 32x24px */
    static const char PROGMEM walk[6][LUNA_SIZE] = {
        /* 'walk1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
		0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
		0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		/* 'walk2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
		0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
		0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Run - 32x24px */
    static const char PROGMEM run[6][LUNA_SIZE] = {
        /* 'run1' */
        {    0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
		0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
		0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00},
         /* 'run2' */
        {    0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
		0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Bark - 32x24px */
    static const char PROGMEM bark[6][LUNA_SIZE] = {
        /* 'bark1' */
        {    0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        /* 'bark2' */
        {    0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Sneak - 32x24px */
    static const char PROGMEM sneak[6][LUNA_SIZE] = {
        /* 'sneak1' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
		0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
		0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00},
        /* 'sneak2' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
		0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
		0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* animation */
    void animate_luna(void) {

	// Render QMK Logo, has been placed inside Luna code due to OLED Flicker
	oled_render_image(4, 32, qmk_logo, LOGO_X, LOGO_Y, 0);

		/* jump */
        if (isJumping || !showedJump) {

            // Is jumping, clear the bottom line and tell animation to render 1 line up
            oled_set_cursor(LUNA_X,LUNA_Y +3);
            oled_write("     ", false);
			jump_height = 1;
            showedJump = true;
        } else {

            // Not jumping, clears the top row and tells animation to render bottom 3 rows
            oled_set_cursor(LUNA_X,LUNA_Y);
            oled_write("     ", false);
			jump_height = 0;
        }

        /* switch frame */
        // current_frame = (current_frame + <number of lines per image>) % <lines x how many frames>;
		current_frame = (current_frame + 3) % 6;

        /* current status */
        if(host_keyboard_led_state().caps_lock) {
            oled_render_image(3, LUNA_SIZE, bark, LUNA_X, LUNA_Y + 1, current_frame);

        } else if(isSneaking) {
			oled_render_image(3, LUNA_SIZE, sneak, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        } else if(prev_wpm <= MIN_WALK_SPEED) {
			oled_render_image(3, LUNA_SIZE, sit, LUNA_X, LUNA_Y + 1, current_frame);

        } else if(prev_wpm <= MIN_RUN_SPEED) {
			oled_render_image(3, LUNA_SIZE, walk, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        } else {
			oled_render_image(3, LUNA_SIZE, run, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        }
    }

	if (keystroke > OLED_TIMEOUT) { oled_off(); }
	else if (timer_elapsed(anim_timer) > (LUNA_FRAME_DURATION - (prev_wpm/2))) {
		anim_timer = timer_read();
		animate_luna();
	}
}

/* KEYBOARD PET END */


bool oled_task_user(void) {

    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        /*static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};*/
        // clang-format on

		/* KEYBOARD PET START */
    	render_luna(1,1,15,0); // (luna X pos, luna Y pos, QMK X pos, QMK Y pos) note that Luna is 4 lines tall Y settings must be 0 on 128x32 display
    	/* KEYBOARD PET END */

		//oled_write_P(qmk_logo, false);
        //oled_write_P(PSTR("\nKyria 2.1\n\n"), false);

		/* wpm counter */
        oled_set_cursor(2,6); // sets position where "wpm" will be displayed
        oled_write("WPM -", false);

        uint8_t n = get_current_wpm();
        char wpm_str[4];
        oled_set_cursor(8,6); // sets position where WPM counter will be displayed
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + ( n /= 10) % 10;
        wpm_str[0] = '0' + n / 10;
        oled_write(wpm_str, false);

		// clear upper right screen half
		oled_set_cursor(7,0);
        oled_write_P(PSTR("\n"), false);
		// clear upper right screen half
		oled_set_cursor(7,1);
        oled_write_P(PSTR("\n"), false);
        // Host Keyboard Layer Status
       	oled_set_cursor(7,2); // sets position where "Layer" will be displayed
        oled_write_P(PSTR("Layer:\n"), false);

        // Host Keyboard Layer Status
       	oled_set_cursor(7,3); // sets position where layer name will be displayed
        switch (get_highest_layer(layer_state)) {
            case _QWERTY_BIO:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV_BIO:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _SYM_BIO:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _NUM_BIO:
                oled_write_P(PSTR("Numbers/Swe\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        //led_t led_usb_state = host_keyboard_led_state();
        //oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        //oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        //oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    } else {
        //// clang-format off
        //static const char PROGMEM kyria_logo[] = {
        //    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //    0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //    0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        //    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        //    0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //    0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        //};
        //// clang-format on
        //oled_write_raw_P(kyria_logo, sizeof(kyria_logo));

		oled_set_cursor(2,2); // sets position where "wpm" will be displayed
        oled_write("Engis' Kyria", false);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* KEYBOARD PET STATUS END */
	}
	return true;
}

#endif
/*
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

