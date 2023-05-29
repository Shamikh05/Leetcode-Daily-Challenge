class ParkingSystem {
private:
    vector<int> parking;
public:
    ParkingSystem(int big, int medium, int small) {
        parking = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return --parking[carType-1] >= 0;
    }
};