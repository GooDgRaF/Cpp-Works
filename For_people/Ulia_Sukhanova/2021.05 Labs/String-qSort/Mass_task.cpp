//
// Created by Антон on 17.05.2021.
//

#include <ctime>
#include <fstream>
#include <iostream>
#include "Mass_task.h"
#include "TinyXML/tinyxml.h"

using namespace std;

Experiment read_from_XML()
    {
        TiXmlDocument doc("Mass_task.xml");
        if (!doc.LoadFile())
            exit(-1);
        
        
        TiXmlElement *experiment_type = doc.FirstChildElement("experiment");
        Experiment experiment;
        experiment.name = experiment_type->Attribute("name");
        
        TiXmlElement *exp = experiment_type->FirstChildElement("node_a");
        
        experiment.arith =
                {
                        exp->Attribute("name"),
                        atoi(exp->Attribute("minElement")), atoi(exp->Attribute("maxElement")),
                        atoi(exp->Attribute("startLength")), atoi(exp->Attribute("maxLength")),
                        atoi(exp->Attribute("repeat")), atoi(exp->Attribute("diff"))
                };
        return experiment;
    }

v_str generate_v_str(size_t row_size, size_t minLen, size_t maxLen)
    {
        v_str vStr;
        vStr.resize(row_size);
        
        for (auto &str : vStr)
        {
            str = generate_str(minLen, maxLen);
        }
        
        return vStr;
    }

std::string generate_str(size_t minLen, size_t maxLen)
    {
        size_t len = rand_len(minLen, maxLen);
        string str;
        str.resize(len, '1');
        return str;
    }

size_t rand_len(size_t minLen, size_t maxLen)
    {
        static bool is_first_launch = true;
        if (is_first_launch)
        {
            srand(time(nullptr));
            is_first_launch = false;
        }
        return minLen + rand()%(maxLen - minLen + 1);
    }

void Experiment::fill_mt()
    {
        a_mt.reserve(arith.repeat*((arith.maxElem - arith.minElem)/arith.diff + 1));
        
        for (auto &vStr : a_mt)
        {
            vStr.reserve(arith.maxLen);
            for (auto &str: vStr)
            {
                str.reserve(arith.maxElem);
            }
        }
        
        for (size_t len = arith.startLen; len <= arith.maxLen; len += arith.diff)
        {
            for (size_t r = 0; r < arith.repeat; ++r)
            {
                a_mt.push_back(generate_v_str(len, arith.minElem, arith.maxElem));
            }
        }
    }

void Experiment::sort_mt()
    {
        v__strLen_numOp.reserve(a_mt.size());
        for (auto &vStr : a_mt)
        {
            size_t numOp{0};
            numOp = qSort(vStr);
            v__strLen_numOp.push_back({vStr.size(), numOp});
        }
    }

void Experiment::write()
    {
        std::ofstream out("Mass_task_res.txt");
        if (out.fail())
        {
            std::cerr << "Can't reach or open file: ../Mass_task_res.txt: " << std::endl;
            exit(-1);
        }
        if (!(v__strLen_numOp.empty()))
        {
            for (auto pair : v__strLen_numOp)
            {
                out << pair.first << " " << pair.second << endl;
            }
        }
        out.close();
    }

void do_mass_task()
    {
        Experiment exp = read_from_XML();
        
        exp.fill_mt();
        exp.sort_mt();
        exp.write();
        
        cout << "XML computation finished." << endl << endl;
    }
