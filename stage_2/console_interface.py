def create_map():
    #нужно вызвать конструктор Area
    print('-The map is created')
    return map

def print_map(map):
    #метод show_area()
    print('W-wolf, H-hare, C-cabbage')
    return None

def model_step(map):
    #метод make_step смоделирует 1 шаг, current_step() вернёт текущий шаг
    print('-Done! Current step:')
    return None

def model_start(map):
    while True:
        iter = int(input("-Enter amount of iterations: "))
        if(iter<0):
            print('Amounts of iterations must be >0')
        else:
            break
    print(f'-Modelling {iter} steps...')
    #for i in range(0,iter):
        #метод make_step произведёт шаг
        #для каждого шага нужно будет обработать то, что вернёт print_info и записать в массив
    return None

def current_stats(map):
    print('-Model statistics at step=') #current_step вернёт текущий шаг
    # метод print_info вернёт статистику
    return None

def all_stats(map):
    print('-Statistics saved at /stats.xlsx') #сохраним в файл то, что записали в model_start
    return None

def quit(map):
    print('-Model stopped') #надо ещё почистить данные c++
    exit(0)
    return None

def print_menu(menu):
    print('-Menu:')
    for i,(menu_str, _) in enumerate(menu):
        print(f'{i+1}. {menu_str}')

def handle_menu(menu):
    while True:
        try:
            num_str = input()
            num = int(num_str)
            return menu[num-1][1]
        except (ValueError, IndexError):
            print(f'-Please enter a number from 1 to {len(menu)}')
            pass


def main():
    # создаём карту
    map = create_map()
    # menu :: [(строка меню, запускаемая функция)]
    menu = [('Print map', print_map),
            ('Model step', model_step),
            ('Start modelling', model_start),
            ('Current stats', current_stats),
            ('All stats', all_stats),
            ('Quit', quit)]
    print_menu(menu)
    while True:
        func = handle_menu(menu)
        func(map)

if __name__ == '__main__':
    main()
