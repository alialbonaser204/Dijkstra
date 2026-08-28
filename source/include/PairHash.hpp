#pragma once
/**
 * @brief Templated operator() functie om de hash te berekenen voor een gegeven pair.
 * @tparam T1 Het type van het eerste element van de pair.
 * @tparam T2 Het type van het tweede element van de pair.
 * @param p Een constante referentie naar een pair van typen T1 en T2.
 * @return De gecombineerde hash van de twee elementen.
 */
struct PairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first); /**< Bereken de hash van het eerste element van de pair. */
        auto hash2 = std::hash<T2>{}(p.second); /**< Bereken de hash van het tweede element van de pair. */
        return hash1 ^ hash2; /**< Combineer de twee hashes met een XOR-bewerking. */
    }
};