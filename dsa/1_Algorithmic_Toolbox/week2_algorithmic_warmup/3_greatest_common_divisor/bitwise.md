When to Use Bitwise Operators vs. Arithmetic Operators

While modern compilers are great at optimizing arithmetic ($+, -, *, /$) into bitwise operations behind the scenes, there are several scenarios where bitwise operators ($\&, \vert{}, \wedge, \sim, <<, >>$) are not just optional optimizations, but the correct tool for the job.

1. Bitmasking and Grouping Flags (State Management)

In memory-constrained environments or high-performance systems, you often want to pack multiple boolean flags into a single integer.

Instead of creating 8 separate bool variables (which would take up 8 bytes of memory), you can store 8 independent on/off states inside a single uint8_t (1 byte of memory) using bitwise operations:

To set a flag (turn ON): Use Bitwise OR (|)

To clear a flag (turn OFF): Use Bitwise AND (&) with a inverted mask (~)

To toggle a flag: Use Bitwise XOR (^)

To check a flag: Use Bitwise AND (&)

Example: Game Actor States

const uint8_t IS_ALIVE      = 1 << 0; // 00000001
const uint8_t IS_POISONED   = 1 << 1; // 00000010
const uint8_t IS_FROZEN     = 1 << 2; // 00000100
const uint8_t CAN_FLY       = 1 << 3; // 00001000

uint8_t playerState = 0; // 00000000 (Dead, clean)

// Player spawns and can fly
playerState |= (IS_ALIVE | CAN_FLY); // 00001001

// Check if player is frozen
if (playerState & IS_FROZEN) {
    // This cannot be done easily with standard division or addition!
}


2. Low-Level Protocols and Serialization

When your code interacts with hardware, network sockets, or binary file formats (like PNGs, MP3s, or ZIPs), data is packed at the bit level to save bandwidth.

For example, network packets often pack a 4-bit version number, a 4-bit header length, and an 8-bit type of service into a single 16-bit block. You must use bitwise shifts and masks to extract or write these values.

Example: Extracting RGB colors from a 32-bit pixel

uint32_t pixel = 0xFF34A2FF; // RRGGBBAA in hex

uint8_t red   = (pixel >> 24) & 0xFF; // Shift right 24 bits, mask the last 8
uint8_t green = (pixel >> 16) & 0xFF; // Shift right 16 bits, mask the last 8
uint8_t blue  = (pixel >> 8)  & 0xFF; // Shift right 8 bits, mask the last 8


3. Cryptography and Hashing Algorithms

In security and checksum algorithms (like SHA-256, MD5, or CRC32), the goal is to scramble data in a highly unpredictable but reversible way.

These algorithms rely heavily on the XOR (^) operator because of its unique mathematical property:
If $A \wedge B = C$, then $C \wedge B = A$.
This makes XOR the foundation of symmetric encryption, parity checks, and generating unique hash keys.

4. Embedded Systems and Register Manipulation

If you ever write C++ for microcontrollers (like Arduino, STM32, or ESP32) or write device drivers, you will interact directly with hardware registers.

To turn on a physical pin on a chip, you don't call a function; you write to a specific memory address. You cannot use + or - because you might accidentally modify other pins on the same port. You must use & and | to change only the specific bit controlling your physical target.
