// Class : SatisfactionUI
// Description: This is a Satisfaction boundary class. 
// Created: 2022/5/30 10:00 pm
// Author: Jiyeon Baek
// mail: etety39@g.hongik.ac.kr

#include <iostream>

class SatisfactionUI{
public: 
    SatisfactionUI(FILE *in_fp, FILE *out_fp);
    void inputPurchaseSatisfaction();
    void enable();
};