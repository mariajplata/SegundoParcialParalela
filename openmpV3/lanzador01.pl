#!/usr/bin/perl

# Fichero para automatización de ejecución por lotes de un ejecutable
# dado parámetros de entrada.
# $ --> variable
# @ --> vector
$repeticiones = 30;
@ejecutables = ("MM1fu");
@matrizSize = ("3", "4", "5", "10", "100", "400", "800", "1000", "2500", "5000");
@cores = ("1","2","3","4");
$path = "/home/yeyaplinux/Documents/openmpV3/";

foreach $exe (@ejecutables) {
	foreach $size (@matrizSize) {
		foreach $core (@cores){
			$fichero = "$path"."Soluciones/"."$exe"."-size"."$size"."-core"."$core";
			#print("$fichero\n");
			for ($i=0; $i<$repeticiones; $i++) {
				#print("$path$exe $size\n");
				system("$path$exe $size $core >> $fichero");
			}
		}
	}
}
exit(1);
