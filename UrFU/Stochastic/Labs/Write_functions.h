//
// Created by Антон on 21.03.2021.
//

#ifndef LABA1_WRITE_FUNCTIONS_H
#define LABA1_WRITE_FUNCTIONS_H

void write_vector_in_file(const std::vector<double> &v, const std::string &path, const bool clear_up = true);

void write_two_vectors(const std::string &path, const std::vector<double> &data_set, const std::vector<double> &N_set);


#endif //LABA1_WRITE_FUNCTIONS_H
