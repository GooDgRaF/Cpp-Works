clc
clear
close

name_of_method_string = "sample12";
title_string = "";
drawInaccuracy(name_of_method_string,title_string);

name_of_method_string = "sampleBM";
title_string = "";
drawInaccuracy(name_of_method_string,title_string);

name_of_method_string = "sampleNormal";
title_string = "All";
drawInaccuracy(name_of_method_string,title_string);

legend('Method 12','Box-Mueller','std::Normal');