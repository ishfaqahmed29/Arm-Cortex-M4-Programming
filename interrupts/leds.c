//This function initializes all the LEDs

void init_RGB(void)
{ 
    GPIOB -> ODR |= ODR(RED_LED); 
    GPIOC -> ODR |= ODR(GREEN_LED); 
    GPIOA -> ODR |= ODR(BLUE_LED); 
}

//This functions toggles all the LEDs

void toggle_all(void)
{   
    GPIOB -> ODR ^= ODR(RED_LED);   
    GPIOC -> ODR ^= ODR(GREEN_LED); 
    GPIOA -> ODR ^= ODR(BLUE_LED); 
} 

//Toggles state of red LED 
void toggle_r(void)
{
    GPIOB -> ODR ^= ODR(RED_LED);   
} 

//Toggles state of green LED 
void toggle_g(void)
{
    GPIOC -> ODR ^= ODR(GREEN_LED);   
} 

//Toggles state of blue LED 
void toggle_b(void)
{
    GPIOA -> ODR ^= ODR(BLUE_LED);   
}
