// Class : Satisfaction
// Description: This is a Satisfaction control class. 
// Created: 2022/5/30 10:00 pm
// Author: Jiyeon Baek
// mail: etety39@g.hongik.ac.kr

#include <iostream>

class Satisfaction{
public: 
    Satisfaction(FILE *in_fp, FILE *out_fp);
    void transferSatisfaction(FILE *in_fp, FILE *out_fp);
};