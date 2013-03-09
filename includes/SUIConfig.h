/*
 *
 * SUIConfig.h -- SerialUI compile time configuration.
 * Copyright (C) 2013 Pat Deegan.  All rights reserved.
 *
 * http://www.flyingcarsandstuff.com/projects/SerialUI
 *
 * Please let me know if you use SerialUI in your projects, and
 * provide a URL if you'd like me to link to it from the SerialUI
 * home.
 *
 *
 * This program library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See file LICENSE.txt for further informations on licensing
 * terms.
 *
 *  ************************* OVERVIEW *************************
 *  This file is used to determine compile-time settings, for
 *  optimizations and determining which resource files to use
 *  (e.g. for language strings).
 *
 *  See below for available flags.
 */
#ifndef SUIConfig_h
#define SUIConfig_h


#define SERIAL_UI_VERSION		1
#define SERIAL_UI_SUBVERSION	0

/* ****************** COMPILE CONFIGURATION DEFINES ****************** */

/*
 * SUI_SERIALUI_ECHO_ON
 * Define SUI_SERIALUI_ECHO_ON to echo user input back out as it is sent.
 * Provides more natural feedback when a user (rather than a program) is
 * present.
 */
#define SUI_SERIALUI_ECHO_ON


/*
 * SUI_SERIALUI_SHOW_PROMPTS
 * Define SUI_SERIALUI_SHOW_PROMPTS to output prompts, e.g.
 *  >
 * Provides visual feedback to users, notifying them the
 * SerialUI is ready for input.
 */
#define SUI_SERIALUI_SHOW_PROMPTS



/*
 * SUI_STRINGS_LANGUAGE_XX
 *
 * Define ONE OF the available SUI_STRINGS_LANGUAGE_XX
 * to select the language of system strings.
 *
 * Only SUI_STRINGS_LANGUAGE_EN and
 * SUI_STRINGS_LANGUAGE_FR are available for now.
 */
// #define SUI_STRINGS_LANGUAGE_FR
#define SUI_STRINGS_LANGUAGE_EN



/* ******* Optional error checking and functionality ********
 * With everything on, meaning:
 *
 *	- SUI_INCLUDE_EXTRA_SAFETYCHECKS (default: enabled)
 *	- SUI_INCLUDE_DEBUG	(default: disabled)
 *	- SUI_SERIALUI_ECHO_WARNINGS (default: enabled)
 *	- SUI_MENU_INCLUDE_DESTRUCTION_CLEANUP (default: disabled)
 *	- SUI_MENU_ENABLE_SUBMENUS  (default: enabled)
 *
 * You'll use up about 1.5k extra in compiled code space as compared
 * to having all the above disabled.
 *
 * You can disable each of these, by commenting out the #defines,
 * when you know all is going according to plan and have determined
 * you don't need that specific functionality.
 *
 */



/*
 * SUI_INCLUDE_EXTRA_SAFETYCHECKS
 * Define SUI_INCLUDE_EXTRA_SAFETYCHECKS to include sanity checks.
 *
 * Disable this (undefine it/comment it out) if you know everything is
 * working and you're tight on flash space.
 */
#define SUI_INCLUDE_EXTRA_SAFETYCHECKS


/*
 * SUI_SERIALUI_ECHO_WARNINGS
 * Define SUI_SERIALUI_ECHO_WARNINGS to output warnings (mainly related to
 * memory allocation issues).
 *
 * Disable this (undefine it/comment it out) if you know everything is
 * working and you're tight on flash space.
 */
#define SUI_SERIALUI_ECHO_WARNINGS



/*
 * SUI_MENU_ENABLE_SUBMENUS
 *
 * Normally, SerialUI supports both command and submenu type menu items, along with
 * menu hierarchy navigation.  This only takes up about 600 bytes but, if space is
 * really super tight and you only plan to have a one-level menu system, then you
 * may undefine SUI_MENU_ENABLE_SUBMENUS and save that space.
 */
#define SUI_MENU_ENABLE_SUBMENUS


/*
 * SUI_INCLUDE_DEBUG
 * Define SUI_INCLUDE_DEBUG to include extra debug output.
 *
 * If SUI_INCLUDE_DEBUG is defined, you may use SerialUI::debug(const char*) to
 * output debug messages (wrap these calls in an #ifdef, or it'll puke when you
 * undefine SUI_INCLUDE_DEBUG).
 *
 * Disabled by default.
 */
//#define SUI_INCLUDE_DEBUG




/*
 * SUI_MENU_INCLUDE_DESTRUCTION_CLEANUP
 *
 * Destruction/clearing of menu items would be useful if you are dynamically modifying
 * the menu structure.  This functionality takes up space that is usually unneeded, so
 * you'll have to define SUI_MENU_INCLUDE_DESTRUCTION_CLEANUP here to include the
 * functionality.
 *
 * Disabled by default.
 */
// #define SUI_MENU_INCLUDE_DESTRUCTION_CLEANUP




/*
 * SUI_PLATFORM_X
 *
 * Define ONE OF the available SUI_PLATFORM_X values to select the serial
 * implementation platform.
 *
 * Only SUI_PLATFORM_ARDUINOSERIAL working for now, SUI_PLATFORM_DIGISPARKUSB is
 * a work in-progress for digistump Digispark USB serial comm... not sure
 * I'll be able to get it usable in such a tight space (a whole
 * 6k of flash available!!1!).
 *
 * NOTE: for SUI_PLATFORM_DIGISPARKUSB, I've had to add a
 * 	#include <DigiUSB.h>
 * at the top of my sketch to get it to compile at all...
 */
//#define SUI_PLATFORM_DIGISPARKUSB
#define SUI_PLATFORM_ARDUINOSERIAL




// Shorthand for Digispark implementation flags
// attempting to reduce code size as
// much as possible (development/currently
// non-functional)
// #define SUI_BUILD_FOR_DIGISPARK

#ifdef SUI_BUILD_FOR_DIGISPARK
#warning "Building for digispark--undef'ing most features"
#undef SUI_INCLUDE_EXTRA_SAFETYCHECKS
#undef SUI_INCLUDE_DEBUG
#undef SUI_SERIALUI_ECHO_WARNINGS
#undef SUI_MENU_INCLUDE_DESTRUCTION_CLEANUP
#undef SUI_MENU_ENABLE_SUBMENUS


#undef SUI_PLATFORM_ARDUINOSERIAL
#define SUI_PLATFORM_DIGISPARKUSB
#endif



#ifdef SUI_INCLUDE_DEBUG
#warning "SUI_INCLUDE_DEBUG is enabled"
#endif


#endif /* SUIConfig_h */
