//
// Created by Антон on 17.05.2021.
//

#include "Mass_task.h"
#include "TinyXML/tinyxml.h"

void do_mass_task()
    { //TODO Сделать массовую задачу
        Experiment mass_qSort = read_from_XML("../Mass_task.xml");
        
    }

Experiment read_from_XML(const std::string &xml_path)
    {
        TiXmlDocument doc(xml_path.c_str());
        if(!doc.LoadFile())
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
        
        exp = exp->NextSiblingElement("node_g");
        
        experiment.geom =
                {
                        exp->Attribute("name"),
                        atoi(exp->Attribute("minElement")), atoi(exp->Attribute("maxElement")),
                        atoi(exp->Attribute("startLength")), atoi(exp->Attribute("maxLength")),
                        atoi(exp->Attribute("repeat")), atof(exp->Attribute("znam"))
                };
        return experiment;
    }
