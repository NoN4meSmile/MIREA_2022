import re # для поиска и обработки тестовой информации
from collections import Counter # для подсчета частоты эл-ов
import math

# Чтение текста из файла
with open('disc.txt', 'r', encoding='utf-8') as file:
    text = file.read()

# Приведение текста к нижнему регистру
text = text.lower()

# Удаление знаков препинания и пробелов
text = re.sub(r'[^\w\s]', '', text)
text = text.replace(' ', '')

# Подсчет частоты появления однобуквенных и двухбуквенных сочетаний
one_letter_counts = Counter(text)
two_letter_counts = Counter([text[i:i+2] for i in range(len(text) - 1)]) # пар в строке всегда на 1 меньше чем символов

# Расчет энтропии
total_characters = len(text)     #кол-во * частоту появления * лог2 част появ
entropy_per_character = -sum((count / total_characters) * math.log2(count / total_characters) for count in one_letter_counts.values())
entropy_per_two_letters = -sum((count / (total_characters - 1)) * math.log2(count / (total_characters - 1)) for count in two_letter_counts.values())

# Расчет длины кода при равномерном побуквенном кодировании
code_length_uniform = math.ceil(math.log2(len(one_letter_counts)))

# Расчет избыточности
redundancy = 1 - (entropy_per_character / code_length_uniform)

# Удаление 20% наиболее часто и наиболее редко встречающихся символов
most_common_characters = [char for char, _ in one_letter_counts.most_common(int(0.2 * len(one_letter_counts)))]
least_common_characters = [char for char, _ in one_letter_counts.most_common()[-int(0.2 * len(one_letter_counts)):]]
filtered_text = ''.join(char for char in text if char not in most_common_characters and char not in least_common_characters)

# Вывод результатов
print(f"Частота появления однобуквенных сочетаний: {one_letter_counts}")
print(f"Частота появления двухбуквенных сочетаний: {two_letter_counts}")
print(f"Энтропия на одну букву: {entropy_per_character}")
print(f"Энтропия на одно двухбуквенное сочетание: {entropy_per_two_letters}")
print(f"Длина кода при равномерном побуквенном кодировании: {code_length_uniform}")
print(f"Избыточность: {redundancy}")
print(f"Текст после удаления символов: {filtered_text}")