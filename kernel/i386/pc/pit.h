#ifndef __PIT_H__
#define __PIT_H__

#define PIT_PORT_CHANNEL_0 0x40
#define PIT_PORT_CHANNEL_1 0x41
#define PIT_PORT_CHANNEL_2 0x42
#define PIT_PORT_COMMAND   0x43

#define PIT_SELECT_CHANNEL(x)		(x << 6)
#define PIT_ACCESS_LOW_BYTE		(1 << 4)
#define PIT_ACCESS_HIGH_BYTE		(1 << 5)
#define PIT_OPERATING_MODE(x)		((x % 5) << 1)
#define PIT_USE_BCD_INSTEAD_OF_BINARY	1

#endif
