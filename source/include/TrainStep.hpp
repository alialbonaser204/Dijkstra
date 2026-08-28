#pragma once
#include "Step.hpp"


// De TrainStep klasse vertegenwoordigt een stap of verbinding per trein tussen twee stations
class TrainStep : public Step {
public:
    // Constructor voor het initialiseren van een trein stap met een startstation, eindstation en gewicht
    TrainStep(Station* from, Station* to, float weight);

    // Methode om het type vervoer te verkrijgen (in dit geval 'Train')
    std::string getTransportType() const override;
};