#include "graph.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace graph;

node::node(std::string data, double score) {
    this->data = data;
    this->score = score;
}

bool node::operator==(node const& n) {
    return this->data == n.data;
}

void node::add_variation(std::string data) {
    if (this->has_variation(data)) return;
    this->variations.push_back(data);
}

void node::remove_variation(std::string data) {
    this->variations.erase(
        std::remove(this->variations.begin(), this->variations.end(), data),
        this->variations.end());
}

bool node::has_variation(std::string data) {
    return std::find(this->variations.begin(), this->variations.end(), data) !=
           this->variations.end();
}

double node::get_averaged_score() {
    return this->score / this->get_variations().size();
}

std::vector<std::string> node::get_variations() {
    return this->variations;
}
