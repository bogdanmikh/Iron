#include <iostream>
class Cloth{
public:
    bool crumpledCloth;
    bool dirtyCloth;
    bool dryCloth;
    std::string typeCloth;
    Cloth ( bool crumpledCloth, bool dirtyCloth,bool dryCloth, std::string typeCloth) {
        this->crumpledCloth = crumpledCloth;
        this->dirtyCloth = dirtyCloth;
        this->dryCloth = dryCloth;
        this->typeCloth = typeCloth;
    }
};
class Iron{
private:
    bool switchedOn;
    int temperature;
    int waterInIron;
    bool switchedOnSteam;
public:
    Iron(int switchedOn,  int temperature, int waterInIron, bool switchedOnSteam) {
        this->switchedOn = switchedOn;
        this->temperature = temperature;
        this->waterInIron = waterInIron;
        this->switchedOnSteam = switchedOnSteam;
    }
    void ironCloth(Cloth* cloth) {
        if (cloth->dryCloth || cloth->dirtyCloth == false) {
            return;
        }
        if (switchedOn) {
            if (cloth->typeCloth[0] == 'V' && cloth->crumpledCloth == false) {
                if (temperature == 120) {
                    cloth->crumpledCloth = true;
                } else {
                    temperature = 120;
                    cloth->crumpledCloth = true;
                }
            } else if (cloth->typeCloth[0] == 'P' && cloth->crumpledCloth == false) {
                if (temperature == 110) {
                    cloth->crumpledCloth = false;
                } else {
                    temperature = 110;
                    cloth->crumpledCloth = false;
                }
            } else if (cloth->typeCloth[0] == 'C' && cloth->crumpledCloth == false) {
                if (temperature == 160) {
                    cloth->crumpledCloth = false;
                } else {
                    temperature = 160;
                    cloth->crumpledCloth = false;
                }
            } else if (cloth->typeCloth[0] == 'S' && cloth->crumpledCloth == false) {
                if (temperature == 60) {
                    cloth->crumpledCloth = false;
                } else {
                    temperature = 60;
                    cloth->crumpledCloth = false;
                }
            } else {
                if (temperature == 180) {
                    cloth->crumpledCloth = false;
                } else {
                    temperature = 180;
                    cloth->crumpledCloth = false;
                }
            }
        }
    }
};

int main() {
    Iron iron(false, 70, 1, false);
    Cloth cloth(false, false, true, "Si");
    iron.ironCloth(&cloth);
    if (cloth.crumpledCloth) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
}
