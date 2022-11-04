#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

class commercialzone : public zonenode {
    private:
        bool futurePop;
    public:
        //Class Constructor
        commercialzone();
        //Getter and Setter
        bool GetFuturePop();

        void SetFuturePop(int futurePopI);
        //Checks for neighbor population if it meets requirements
        bool NeighborPopulationCheck(int popMin, int neighborAmount);

        // What to do when a time step is called
        void ComercialTimeStep(int &availableWorker, int availableGood);
        //Updates the population count
        void UpdatePop();
};

#endif
