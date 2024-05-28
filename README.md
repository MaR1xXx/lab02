## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.

```sh
$ mkdir lab02 && cd lab02
$ git init
$ git remote add origin https://github.com/aakx000/lab02.git
$ git branch -M main
$ git push -u origin main
```

3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.

```sh
$ cat > hello_world.cpp << EOF
#include <iostream>
using namespace std;
int main() {
cout << "Hello, world!" << endl;
return 0;
}
EOF
```

4. Добавьте этот файл в локальную копию репозитория.

```sh
$ git add hello_world.cpp
```
5. Закоммитьте изменения с *осмысленным* сообщением.

```sh
$ git commit -m "add hello_world.cpp"
```

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.

```sh
$ vim hello_world.cpp
```

```sh
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    getline(cin, name);
    cout << "Hello world from " << name << endl;
    return 0;
}
```

7. Закоммитьте новую версию программы.

```sh
$ git commit -m "add hello_world.cpp v2.0"
```

8. Запуште изменения в удалёный репозиторий.

```sh
$ git push origin main
```

9. Проверьте, что история коммитов доступна в удалёный репозитории.

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.

```sh
$ git checkout -b patch1
```
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.

```sh
$ vim hello_world.cpp
```

```sh
#include <iostream>
#include <string>
int main()
{
    std::string name;
    getline(std::cin, name);
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

3. **commit**, **push** локальную ветку в удалённый репозиторий.

```sh
$ git add hello_world.cpp
$ git commit -m "removed using namespace std"
$ git push origin patch1
```

4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
5. Создайте pull-request `patch1 -> master`.
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.

```sh
$ vim hello_world.cpp
```

```sh
#include <iostream>
#include <string>
int main()
{
    std::string name;
    //name input
    getline(std::cin, name);
    
    //output
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

7. **commit**, **push**.

```sh
$ git add hello_world.cpp
$ git commit -m "added comments"
$ git push origin patch1
```

8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
10. Локально выполните **pull**.

```sh
$ git checkout main
$ git pull origin main
```

11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.

```sh
$ git log
```

```sh
commit 431445c5f83513190d03b33f6d7300ccba4dc2d5 (HEAD -> main, origin/main)
Merge: b1081bd ce29bd4
Author: aakx000 <146767192+aakx000@users.noreply.github.com>
Date:   Sun Apr 28 20:16:15 2024 +0300

    Merge pull request #1 from aakx000/patch1
    
    removed using namespace std

commit ce29bd439af26679b3e005991c9fd345fb048749 (origin/patch1, patch1)
Author: aakx000 <aakx0506@gmail.com>
Date:   Sun Apr 28 20:14:45 2024 +0300

    added comments

commit 22493674c359ae0403b9789f1391348fe9704752
Author: aakx000 <aakx0506@gmail.com>
Date:   Sun Apr 28 20:10:41 2024 +0300

    removed using namespace std

commit b80e411212b5b4c784819b5fd7b4aa316a51482e
Author: aakx000 <aakx0506@gmail.com>
Date:   Sun Apr 28 20:07:25 2024 +0300

    removed using namespace std

commit b1081bdc847ad1f830995d413b00e6347ecdd770
Author: aakx000 <aakx0506@gmail.com>
Date:   Sun Apr 28 19:57:35 2024 +0300

    add hello_world.cpp v2.0

commit eb3a8707d04669d78c930e46f1204f6035acce6e
Author: aakx000 <aakx0506@gmail.com>
Date:   Sun Apr 28 13:07:24 2024 +0300

    add hello_world.cpp

```
12. Удалите локальную ветку `patch1`.

```sh
$ git branch -D patch1
Deleted branch patch1 (was ce29bd4).
```

### Part III

**Note:** *Работать продолжайте с теми же репозиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.

```sh
$ git checkout -b patch2
```

2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.

```sh
$ clang-format  -style=Mozilla hello_world.cpp
$ vim hello_world.cpp
```

```sh
#include <iostream>
#include <string>
int
main()
{
  std::string name;
  // name input
  getline(std::cin, name);

  // output
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}
```

3. **commit**, **push**, создайте pull-request `patch2 -> master`.

```sh
$ git add hello_world.cpp
$ git commit -m "mozilla codestyle"
$ git push origin patch2
```

4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.

```sh
$ vim hello_world.cpp
```

```sh
#include <iostream>
#include <string>
int main()
{
    std::string name;
    //ввод имени
    getline(std::cin, name);
    
    //вывод
    std::cout << "Hello, world from " << name << std::endl;
    return 0;
}
```

5. Убедитесь, что в pull-request появились *конфликтны*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.

```sh
$ git pull origin main --rebase

From https://github.com/aakx000/lab02
 * branch            main       -> FETCH_HEAD
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 220f553... mozilla codestyle
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 220f553... mozilla codestyle
```

```sh
$ vim hello_world.cpp
```

```sh
$ git add .
$ git commit -m "final commit"
$ git rebase --continue
Successfully rebased and updated refs/heads/patch2.
```

7. Сделайте *force push* в ветку `patch2`

```sh
$ git push -f origin patch2
```
8. Убедитель, что в pull-request пропали конфликтны. 
9. Вмержите pull-request `patch2 -> master`.

```
Copyright (c) 2015-2021 The ISC Authors
```
