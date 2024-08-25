#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "CMCPlugin.h"

void CMCPlugin::input(std::string file) {
 inputfile = file;
}

void CMCPlugin::run() {
   
}

void CMCPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; python2 plugins/CMC/cmc-2010.03.15/cmc.py ";
// python2 code/pafscaff.py seqin=Pseudomonas_aeruginosa_F63912_7033.fna reference=Pseudomonas_aeruginosa_PAO1_107.fna


 command += " -i "+inputfile;
 command += " -o "+file;
 //; export PYTHONPATH=OLDPATH"; 
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<CMCPlugin> CMCPluginProxy = PluginProxy<CMCPlugin>("CMC", PluginManager::getInstance());
