Trayectoria.png : datos1.dat datos2.dat ProyecFric.py
	python ProyecFric.py
	
datos1.dat : ProyecFric.x
	./ProyecFric.x 1 >> datos1.dat
	
datos2.dat : ProyecFric.x
	./ProyecFric.x 0 >> datos2.dat

ProyecFric.x : ProyecFric.cpp
	c++ ProyecFric.cpp -o ProyecFric.x