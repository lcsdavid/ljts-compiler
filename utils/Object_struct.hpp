#ifndef OBJECT_STRUCT_HPP
#define OBJECT_STRUCT_HPP

#include<Vector>

typedef struct Object_struct {
	
	std::string m_nom;
	std::vector<Param_srtuct *> m_listParam;
	std::vector<Methode_struct *> m_listMethode;
	
}Object_struct;

typedef struct Methode_struct{
	
	std::string m_nom;
	std::vector<Param_srtuct *> m_listParam;
	std::
	
	
}Methode_struct;




#endif