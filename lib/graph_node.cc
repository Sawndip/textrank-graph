#include "graph.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace graph;

/**
 * Create new node.
 * \param data Data of the node.
 * \param score Initial node score.
 */
node::node(std::string data, double score) {
    this->data = data;
    this->score = score;
}

/**
 * Compares equality of nodes. Equality is based purely on the `data` of the node.
 * \param n Node to compare to.
 */
bool node::operator==(node const& n) {
    return this->data == n.data;
}

/**
 * Adds a variation to the node.
 * \param data Variation to add.
 */
void node::add_variation(std::string data) {
    if (this->has_variation(data)) return;
    this->variations.push_back(data);
}

/**
 * Removes a variation from the node.
 * \param data Variation to remove.
 */
void node::remove_variation(std::string data) {
    this->variations.erase(
        std::remove(this->variations.begin(), this->variations.end(), data),
        this->variations.end());
}

/**
 * Checks if the node has a variation.
 * \param data Variation to search for.
 */
bool node::has_variation(std::string data) {
    return std::find(this->variations.begin(), this->variations.end(), data) !=
           this->variations.end();
}

/**
 * Gets the score of the node averaged over all variations.
 */
double node::get_averaged_score() {
    return this->score / this->get_variations().size();
}

/**
 * Gets the variations of the node.
 */
std::vector<std::string> node::get_variations() {
    return this->variations;
}
