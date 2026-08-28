#pragma once
#include <vector>
#include <unordered_map>
#include <queue>
#include "Station.hpp"
#include "Step.hpp"
#include "PairHash.hpp"

/**
 * @class Graph
 * @brief De Graph klasse vertegenwoordigt een graaf bestaande uit stations en stappen (verbindingen tussen stations).
 */

class Graph {
private:
    std::vector<Station*> stations;  /**< Een vector die alle stations in de graaf bevat. */
    std::vector<Step*> steps;        /**< Een vector die alle stappen in de graaf bevat.*/

public:
    /**
     * @brief Constructor die de graaf initialiseert met een gegeven lijst van stations en stappen.
     * @param stations Een vector van pointers naar stations.
     * @param steps Een vector van pointers naar stappen.
     */

     Graph(const std::vector<Station*>& stations, const std::vector<Step*>& steps);

    /**
     * @brief Methode om alle stations in de graaf te verkrijgen.
     * @return Een vector van pointers naar stations.
     */

     std::vector<Station*> getStations() const;

    /**
     * @brief Methode om alle stappen in de graaf te verkrijgen.
     * @return Een vector van pointers naar stappen.
     */

    std::vector<Step*> getSteps() const;

    /**
     * @brief Methode die het Dijkstra-algoritme uitvoert om de kortste paden vanaf een startstation te berekenen.
     * @param bron Pointer naar het startstation.
     * @return Een paar van:
     * - Een map van stations naar de kortste afstand vanaf het startstation.
     * - Een map van stations naar de voorgaande stappen op het kortste pad.
     */

    std::pair<std::unordered_map<Station*, float>, std::unordered_map<Station*, Step*>> dijkstra(Station* bron);

    /**
     * @brief Hulpmethode om het pad te printen van een startstation naar een eindstation.
     * Gebruikt een map van voorgaande stappen om het pad te reconstrueren.
     * @param start Pointer naar het startstation.
     * @param end Pointer naar het eindstation.
     * @param predecessors Een map van stations naar hun voorgangers op het kortste pad.
     */

    void printPathHelper(Station* start, Station* end, const std::unordered_map<Station*, Step*>& predecessors) const;

    /**
     * @brief Methode om het volledige pad te printen van een startstation naar een eindstation.
     * Gebruikt de printPathHelper methode om het pad te reconstrueren en te printen.
     * @param start Pointer naar het startstation.
     * @param end Pointer naar het eindstation.
     * @param predecessors Een map van stations naar hun voorgangers op het kortste pad.
     */

   void printPath(Station* start, Station* end, const std::unordered_map<Station*, Step*>& predecessors) const;
};
