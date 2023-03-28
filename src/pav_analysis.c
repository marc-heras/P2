#include <math.h>
#include "pav_analysis.h"
#define signo(x) (x>0 ? 1 : x<0 ? -1 : 0)

float compute_power(const float *x, unsigned int N) {
    float power=1e-12;
    for(unsigned int i=0; i<N; i++){
        power += x[i] * x[i];
    }
    return 10*log10(power/N);
}

float compute_am(const float *x, unsigned int N) {
    float am;
    for(int i=0; i<N; i++){
        am=am+fabs(x[i]);
    }
    am=am/N;
    return am;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr=0;
    for(int i=1; i<N; i++){
        if(signo(x[i-1]) != signo(x[i])){
            zcr += 1;
        }
    }
    return fm/(2*(N-1))*zcr;
}
