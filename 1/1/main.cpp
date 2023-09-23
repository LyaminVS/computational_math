#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

double C(int n, int k){
    return tgamma(n + 1) / tgamma(n - k + 1) / tgamma(k + 1);
}

std::vector<double> get_coefs(){
    std::vector<double> coefs;
    for (int i = 0; i < 10; i++) {
        coefs.push_back(C(9, 9 - i) * pow(-2, 9 - i));
    }
    return coefs;
}

double gorner(int N, std::vector<double> &a, double x){
    double p = a[N];
    for (int j = N - 1; j >= 0; j--) {
        p = x * p + a[j];
    }
    return p;
}

void dump(std::string filename, int point_number, std::vector<double>& args, std::vector<double>& answers){
        std::ofstream file(filename);
        for (int i = 0; i < point_number; i++) {
            file << std::scientific << args[i] << " " << answers[i] << std::endl;
         }
    }

int main(int argc, const char * argv[]) {
    int N = 9;
    std::vector<double> a = get_coefs();
    std::vector<double> answers;
    std::vector<double> answers_brute_force;
    std::vector<double> args;
    int point_number = 0;
    
    for (double x = 1.92; x <= 2.08; x += 1e-4) {
        answers.push_back(gorner(N, a, x));
        answers_brute_force.push_back(pow(x - 2, 9));
        args.push_back(x);
        point_number++;
        std::cout << gorner(N, a, x) << std::endl;
    }
    
    dump("data_gorner.txt", point_number, args, answers);
    dump("data_brute_force.txt", point_number, args, answers_brute_force);

    return 0;
}


