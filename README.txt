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

	- (ветка hash) Более сложная, основанная на хэшировании файлов.
	Соответственно, сравниваются хэши. Файлы при этом читаются по одному разу.
	Ее недостаток - она работает сильно медленнее: MD5, 100мс против 500мс (папки 13 элем., 40 мб / 21 элем., 64 мб),
	поскольку издержки на хэширование превышают издержки на повторное частичное чтение файлов.

Моя текущая цель - это оптимизировать оба решения и сравнить их.

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

	- (branch hash) More complex, based on file hashing.
	Respectively, hashes are compared. The files are read only once.
	It's disadvantage - it works much slower: MD5, 100ms vs 500ms (folders 13 elem., 40 mb / 21 elem., 64 mb),
	since hashing overhead exceeds repeated partial file reading overhead. 

My current goal is to optimize both solutions and check the difference.