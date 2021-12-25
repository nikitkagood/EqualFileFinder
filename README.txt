Это проект Visual Studio. 
Зависимости: расширение Qt VS Tools + сам Qt, присоедененный к расширению.

Управление: ПКМ, выбрать папки, потом нажать Start
Можно использовать приложенные папки для тестового поиска

Файл с выводом появится в папке с проектом.
Если его там нет, то в папке с .exe.

Существуют 2 версии: 
	- (ветка main) Простая. Она считывает информацию из файла порциями в 2 буфера, потом их сравнивает.
	И так до появления различий или до конца файлов.
	Она работает быстро. Особенно на меньших данных.
	Ее недостатаок - чтение файлов происходит по нескольку раз (пусть чаще всего и не полностью).

	- (ветка hash_version) Более сложная, основанная на хэшировании файлов.
	Соответственно, сравниваются хэши. Файлы при этом читаются по одному разу.
	Ее недостаток - она работает сильно медленнее (по крайней мере с SHA1),
	поскольку издержки на хэширование превышают издержки на повторное частичное чтение файлов.


=========================================================================
EN:
This is Visual Studio project.
Dependendcies: Qt VS Tools extention + Qt itself connected to the extention.

Controls: RMB, select folders, then push Start
You can use the attached test folders.

An output file will appear in the project folder. 
If it's not there, then it must be a folder where .exe is at.

There are 2 versions:
	- (branch main) Simple one. It reads data into 2 buffers in portions, then compares them.
	And it goes until differences are found or untill the end of files.
	It works fast. Especially when used on smaller data.
	It's disadvantage - reading is performed several times (though most of the times not fully)

	- (branch hash_version) More complex, based on file hashing.
	Respectively, hashes are compared. The files are read only once.
	It's disadvantage - it works much slower (at least with SHA1),
	since hashing overhead exceeds repeated partial file reading overhead. 
