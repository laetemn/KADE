/* 
 * KADE - Kick Ass Dynamic Encoder
 * Copyright (c) 2012 Bruno Freitas - bruno@brunofreitas.com
 *                    Jon Wilson    - degenatrons@gmail.com
 *                    Kevin Mackett - kevin@sharpfork.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ADDITIONAL TERMS per GNU GPL Section 7
 * No trademark or publicity rights are granted. This license does NOT give you 
 * any right, title or interest in the KADE brand. You may not distribute any 
 * modification of this program using the KADE name or KADE logo or claim any 
 * affiliation or association with KADE or the KADE development team.
 *
 * Any propagation or conveyance of this program must include this copyright 
 * notice and these terms.
 *
 * You may not misrepresent the origins of this program; modified versions of the 
 * program must be marked as such and not identified as the original program.

------------------------------------------------------------------------
   Note from Jon:
   Test for LEDS and HWB Button.
   LEDs will blink unless HWB is pressed. When HWB pressed LEDs stay on
------------------------------------------------------------------------
*/
#include <avr/io.h>
#include <util/delay.h>

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define bit_set(p,m) ((p) |= (m)) 
#define bit_clear(p,m) ((p) &= ~(m)) 

int main(void) {

	CPU_PRESCALE(0);		

    DDRB = 0x00;
    DDRC = 0x00;
    DDRD = 0x60; 
    PORTB = 0xFF;
    PORTC = 0xFF;
    PORTD = 0x9F;
	
	while(1) {
		while (!(PIND & 0x80)) {
			bit_clear(PORTD,0x20);
			bit_clear(PORTD,0x40);		
		}	
		bit_set(PORTD,0x20);
		_delay_ms(125);
		bit_set(PORTD,0x40);
		_delay_ms(125);
		bit_clear(PORTD,0x20);
		_delay_ms(125);
		bit_clear(PORTD,0x40);
		_delay_ms(125);
	}
			
}
