// asm instructions allow more precise delays than the built-in delay functions
// make sure the CPU clock speed has been set to 48 MHz
// for delays over 3us, use the delayMicroseconds() function
#define NOP5 "nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"
#define NOP4 "nop\n\t""nop\n\t""nop\n\t""nop\n\t"
#define NOP10 NOP5 NOP5
#define NOP20 NOP10 NOP10
#define NOP40 NOP20 NOP20

// the relation between the number of instructions and the generated delay is not perfectly linear 
// because of timing jitter and various pipelining artifacts in back to back instructions
#define DELAY_1US __asm__(NOP40 NOP4)
#define DELAY_2US __asm__(NOP40 NOP40 NOP10 NOP4)
#define DELAY_3US __asm__(NOP40 NOP40 NOP40 NOP20)

/*
A few useful functions:

- Atomic section:
	noInterrupts();
	// atomic code
	interrupts();

- Delays over 3us:
	delayMicroseconds(int time);

*/

void setup()
{
    // put your setup code here, to run once:
	
	// status LED
	pinMode(13, OUTPUT);
	digitalWriteFast(13, HIGH);
}

void loop()
{
    // put your main code here, to run repeatedly:
	
}
