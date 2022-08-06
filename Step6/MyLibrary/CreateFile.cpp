#include <fstream>

int main(int argc, char* argv[]){
    std::ofstream fout(argv[1], std::ios_base::out);
    if (fout.is_open()){
        fout << "int table[] = {" << std::endl;
        for (int i = 0; i < 10; i++){
            fout << i * i << "," << std::endl;
        }
        fout << "0};" << std::endl;
        fout.close();

        return 0;
    }
    return 1;
}
