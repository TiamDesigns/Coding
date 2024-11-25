#include <stdio.h>

void generate_disease_spread_data();
void determine_hospital_impact();
void find_max_beta_for_hospital_capacity();

int main() {
    int i = 1;  
    int mode;   

    while (i == 1) {
        printf("choose a menu option:\n");
        printf("1. generate disease spread data for plotting\n");
        printf("2. determine hospital impact\n");
        printf("3. find maximum beta for hospital capacity\n");
        printf("4. exit\n");

        scanf("%d", &mode);

        switch (mode) {
            case 1:
                generate_disease_spread_data();
                break;
            case 2:
                determine_hospital_impact();
                break;
            case 3:
                find_max_beta_for_hospital_capacity();
                break;
            case 4:
                printf("exiting the program. goodbye!\n");
                i = 0;  // stop the loop
                break;
            default:
                printf("invalid option. please try again.\n");
        }
    }

    return 0;
}

// mode 1: generate disease spread data for plotting
void generate_disease_spread_data() {
    const int N = 1000000;  // total population
    double S, I, R;         // SIR variables
    double beta, gamma;     // parameters
    char filename[100];     // file name

    printf("enter beta (infection rate): ");
    scanf("%lf", &beta);
    printf("enter gamma (recovery rate): ");
    scanf("%lf", &gamma);
    printf("enter output file name: ");
    scanf("%s", filename);

    S = N - 200;  // susceptible
    I = 200;      // infected
    R = 0;        // recovered

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("error opening file.\n");
        return;
    }

    //header
    fprintf(file, "day,S,I,R\n");

    // simulate the disease spread
    int day = 0;
    double prevS, prevI, prevR;
    double deltaS, deltaI, deltaR;
    do {

        fprintf(file, "%d,%.2f,%.2f,%.2f\n", day, S, I, R);
 
        prevS = S;
        prevI = I;
        prevR = R;

        deltaS = -beta * I * S / N;
        deltaI = beta * I * S / N - gamma * I;
        deltaR = gamma * I;

        S += deltaS;
        I += deltaI;
        R += deltaR;
        day++;

    } while ((prevS - S > 0.1 || S - prevS > 0.1) || 
             (prevI - I > 0.1 || I - prevI > 0.1) || 
             (prevR - R > 0.1 || R - prevR > 0.1));

    fclose(file);
    printf("data saved to %s.\n", filename);
}

// mode 2: determine the hospital impact
void determine_hospital_impact() {
    const int N = 1000000;  // total population
    const int hospital_beds = 2500;  // total hospital capacity
    double S, I, R;
    double beta, gamma, theta;  
    int hospital_overload = 0;

    // get input from user
    printf("enter beta (infection rate): ");
    scanf("%lf", &beta);
    printf("enter gamma (recovery rate): ");
    scanf("%lf", &gamma);
    printf("enter θ (hospitalization rate): ");
    scanf("%lf", &theta);

    // initial values
    S = N - 200;
    I = 200;
    R = 0;

    // simulate the disease spread
    int day = 0;
    double deltaS, deltaI, deltaR;
    while (1) {
        // check if hospital capacity is exceeded
        if (I * theta > hospital_beds) {
            hospital_overload = 1;
            break;
        }

        deltaS = -beta * I * S / N;
        deltaI = beta * I * S / N - gamma * I;
        deltaR = gamma * I;

        S += deltaS;
        I += deltaI;
        R += deltaR;
        day++;

        // tolerance
        if (deltaS > -0.1 && deltaS < 0.1 && deltaI > -0.1 && deltaI < 0.1 && deltaR > -0.1 && deltaR < 0.1) {
            break;
        }
    }

    if (hospital_overload) {
        printf("hospital capacity exceeded on day %d.\n", day);
    } else {
        printf("hospital capacity will not be exceeded.\n");
    }
}

// mode 3: find maximum beta for hospital capacity
void find_max_beta_for_hospital_capacity() {
    const int N = 1000000;  
    const int hospital_beds = 2500; 
    double gamma, theta;
    double beta_low = 0.0, beta_high = 2.0, beta_mid;

    printf("enter gamma (recovery rate): ");
    scanf("%lf", &gamma);
    printf("enter theta (hospitalization rate): ");
    scanf("%lf", &theta);

    // bisection search 
    while (beta_high - beta_low > 0.005) {
        beta_mid = (beta_low + beta_high) / 2.0;

        double S = N - 200;
        double I = 200;
        double R = 0;
        int hospital_overload = 0;
        double deltaS, deltaI, deltaR;
        while (1) {
            if (I * theta > hospital_beds) {
                hospital_overload = 1;
                break;
            }

            deltaS = -beta_mid * I * S / N;
            deltaI = beta_mid * I * S / N - gamma * I;
            deltaR = gamma * I;

            S += deltaS;
            I += deltaI;
            R += deltaR;

            if (deltaS > -0.1 && deltaS < 0.1 && deltaI > -0.1 && deltaI < 0.1 && deltaR > -0.1 && deltaR < 0.1) {
                break;
            }
        }

        if (hospital_overload) {
            beta_high = beta_mid;
        } else {
            beta_low = beta_mid;
        }
    }

    printf("maximum beta for hospital capacity: %.3f\n", beta_low);
}
