void init_switches(void)
{ 
    //Start clocks for ports A, B & C 
    RCC->AHB1ENR |= RCC_PORTC_MASK  | RCC_PORTB_MASK | RCC_PORTA_MASK; 

    //MODER is used to set the direction mode of I/O pins
    GPIOA->MODER &= ~MODER(JOY_UP); 
    GPIOC->MODER &= ~MODER(JOY_RIGHT) | MODER(JOY_LEFT); 
    GPIOB->MODER &= ~MODER(JOY_CENTER); 
}
