// This file was autogenerated from ATmega328.conf. Do not edit manually!
#define SET_BIT_0(name) name ## _reg &= ~(1<<name)
#define SET_BIT_1(name) name ## _reg |= (1<<name)
// registers for all used bit names
#define CS20_reg TCCR2B
#define CS21_reg TCCR2B
#define CS22_reg TCCR2B
#define TOIE1_reg TIMSK1
#define WGM11_reg TCCR1A
#define WGM10_reg TCCR1A
#define WGM13_reg TCCR1B
#define WGM12_reg TCCR1B
#define DORD0_reg SPCR0
#define CS02_reg TCCR0B
#define OCR2AUB_reg ASSR
#define CS00_reg TCCR0B
#define CS01_reg TCCR0B
#define COM2A0_reg TCCR2A
#define COM2A1_reg TCCR2A
#define CPHA0_reg SPCR0
#define TCR2AUB_reg ASSR
#define OCIE2A_reg TIMSK2
#define FOC0A_reg TCCR0B
#define FOC0B_reg TCCR0B
#define COM0A0_reg TCCR0A
#define COM0A1_reg TCCR0A
#define TOIE2_reg TIMSK2
#define TOIE0_reg TIMSK0
#define OC0A_reg TIFR0
#define FOC2B_reg TCCR2B
#define FOC2A_reg TCCR2B
#define SPI2X0_reg SPSR0
#define ICNC1_reg TCCR1B
#define COM1A1_reg TCCR1A
#define COM1A0_reg TCCR1A
#define OCIE1B_reg TIMSK1
#define CPOL0_reg SPCR0
#define AS2_reg ASSR
#define WCOL0_reg SPSR0
#define WGM02_reg TCCR0B
#define SPIF0_reg SPSR0
#define WGM00_reg TCCR0A
#define WGM01_reg TCCR0A
#define CS11_reg TCCR1B
#define CS10_reg TCCR1B
#define CS12_reg TCCR1B
#define WGM20_reg TCCR2A
#define WGM21_reg TCCR2A
#define WGM22_reg TCCR2B
#define SPR00_reg SPCR0
#define COM0B1_reg TCCR0A
#define FOC1A_reg TCCR1C
#define EXCLK_reg ASSR
#define SPE0_reg SPCR0
#define TCN2UB_reg ASSR
#define TOV0_reg TIFR0
#define COM2B1_reg TCCR2A
#define COM2B0_reg TCCR2A
#define FOC1B_reg TCCR1C
#define SPIE0_reg SPCR0
#define OCIE0A_reg TIMSK0
#define COM1B0_reg TCCR1A
#define COM1B1_reg TCCR1A
#define ICIE1_reg TIMSK1
#define ICES1_reg TCCR1B
#define MSTR0_reg SPCR0
#define OCIE1A_reg TIMSK1
#define OCR2BUB_reg ASSR
#define OCIE0B_reg TIMSK0
#define COM0B0_reg TCCR0A
#define OCF0B_reg TIFR0
#define TCR2BUB_reg ASSR
#define OCIE2B_reg TIMSK2
#define SPR01_reg SPCR0
// timer0_mode
inline void timer0_mode_normal();
inline void timer0_mode_pwm_phasecorrect_until_0xFF();
inline void timer0_mode_ctc();
inline void timer0_mode_fast_pwm_until_0xFF();
inline void timer0_mode_pwm_phasecorrect_until_OCR0A();
inline void timer0_mode_fast_pwm_until_OCR0A();
// timer0_clockselect
inline void timer0_clockselect_none();
inline void timer0_clockselect_io_1();
inline void timer0_clockselect_io_8();
inline void timer0_clockselect_io_64();
inline void timer0_clockselect_io_256();
inline void timer0_clockselect_io_1024();
inline void timer0_clockselect_on_falling_T0();
inline void timer0_clockselect_on_rising_T0();
// timer1_mode
inline void timer1_mode_normal();
inline void timer1_mode_pwm_phasecorrect_until_0x00FF();
inline void timer1_mode_pwm_phasecorrect_until_0x01FF();
inline void timer1_mode_pwm_phasecorrect_until_0x03FF();
inline void timer1_mode_ctc_until_OCR1A();
inline void timer1_mode_pwm_fast_until_0x00FF();
inline void timer1_mode_pwm_fast_until_0x01FF();
inline void timer1_mode_pwm_fast_until_0x03FF();
inline void timer1_mode_pwm_phasefrequencycorrect_until_ICR1();
inline void timer1_mode_pwm_phasefrequencycorrect_until_OCR1A();
inline void timer1_mode_pwm_phasecorrect_until_ICR1();
inline void timer1_mode_pwm_phasecorrect_until_OCR1A();
inline void timer1_mode_ctc_until_ICR1();
inline void timer1_mode_pwm_fast_until_ICR1();
inline void timer1_mode_pwm_fast_until_OCR1A();
// timer1_clockselect
inline void timer1_clockselect_none();
inline void timer1_clockselect_io_1();
inline void timer1_clockselect_io_8();
inline void timer1_clockselect_io_64();
inline void timer1_clockselect_io_256();
inline void timer1_clockselect_io_1024();
inline void timer1_clockselect_on_falling_T1();
inline void timer1_clockselect_on_rising_T1();
// timer2_mode
inline void timer2_mode_normal();
inline void timer2_mode_pwm_phasecorrect_until_0xFF();
inline void timer2_mode_ctc_until_OCR2A();
inline void timer2_mode_pwm_fast_until_0xFF();
inline void timer2_mode_pwm_phasecorrect_until_OCR2A();
inline void timer2_mode_pwm_fast_until_OCR2A();
// timer2_clockselect
inline void timer2_clockselect_none();
inline void timer2_clockselect_t2clk_1();
inline void timer2_clockselect_t2clk_8();
inline void timer2_clockselect_t2clk_32();
inline void timer2_clockselect_t2clk_64();
inline void timer2_clockselect_t2clk_128();
inline void timer2_clockselect_t2clk_256();
inline void timer2_clockselect_t2clk_1024();
// spi0_enable
inline void spi0_enable_disable();
inline void spi0_enable_enable();
// spi0_mode
inline void spi0_mode_slave();
inline void spi0_mode_master();
// spi0_polarity
inline void spi0_polarity_leading_rising();
inline void spi0_polarity_leading_falling();
// spi0_phase
inline void spi0_phase_leading_sample();
inline void spi0_phase_leading_setup();
// spi0_clock
inline void spi0_clock_fosc_4();
inline void spi0_clock_fosc_16();
inline void spi0_clock_fosc_64();
inline void spi0_clock_fosc_128();
inline void spi0_clock_fosc_2();
inline void spi0_clock_fosc_8();
inline void spi0_clock_fosc_32();
inline void spi0_clock_fosc_64();
// interrupts
inline void int_timer0_compA_enable();
inline void int_timer0_compA_disable();
inline void int_timer0_compB_enable();
inline void int_timer0_compB_disable();
inline void int_timer0_overflow_enable();
inline void int_timer0_overflow_disable();
inline void int_timer1_input_capture_enable();
inline void int_timer1_input_capture_disable();
inline void int_timer1_compA_enable();
inline void int_timer1_compA_disable();
inline void int_timer1_compB_enable();
inline void int_timer1_compB_disable();
inline void int_timer1_overflow_enable();
inline void int_timer1_overflow_disable();
inline void int_spi0_enable();
inline void int_spi0_disable();