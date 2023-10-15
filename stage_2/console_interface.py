def create_map():
    print('-The map is created')
    return map

def print_map(map):
    print('W-wolf, H-hare. C-cabbage')
    return None

def model_step(map):
    print('-Done! Current_step:')
    print_map(map)
    return None

def model_start(map):
    iter = int(input("Enter amount of iterations: "))
    print(f'-Modelling {iter} steps')
    return None

def current_stats(map):
    print('-Model statistics at step=...:')
    print('       Wolves |Hares    |Cabbages')
    print('Amount:       |         |        ')
    print('Health:       |         |        ')
    return None

def all_stats(map):
    print('-Statistics saved at /stats.xlsx')
    return None

def quit(map):
    print('-Model stopped')
    exit(0)
    return None

def print_menu(menu):
    for i,(menu_str, _) in enumerate(menu):
        print(f'{i+1}. {menu_str}')
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
    while True:
        func = print_menu(menu)
        func(map)

if __name__ == '__main__':
    main()
