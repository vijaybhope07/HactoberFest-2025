from project import load_questions, calculate_winnings, validate_answer, format_currency

def test_load_questions():
    questions = load_questions()
    assert len(questions) == 10
    assert len(questions[0]) == 2  
    assert len(questions[0][1]) == 5  

def test_calculate_winnings():
    assert calculate_winnings(0, True, 0) == 1000
    assert calculate_winnings(1, True, 1000) == 2000
    assert calculate_winnings(9, True, 300000) == 1000000

    assert calculate_winnings(0, False, 0) == 0  
    assert calculate_winnings(2, False, 3000) == 2000  
    assert calculate_winnings(4, False, 10000) == 10000  
    assert calculate_winnings(7, False, 100000) == 100000  


    assert calculate_winnings(1, False, 1000) == 0
    assert calculate_winnings(3, False, 5000) == 2000

def test_validate_answer():

    assert validate_answer(2, 2) == True
    assert validate_answer(1, 1) == True
    assert validate_answer(4, 4) == True

    assert validate_answer(1, 2) == False
    assert validate_answer(3, 1) == False

    assert validate_answer(0, 2) is None
    assert validate_answer(0, 1) is None

def test_format_currency():

    assert format_currency(1000) == "$1,000"
    assert format_currency(1000000) == "$1,000,000"
    assert format_currency(0) == "$0"
    assert format_currency(500) == "$500"
    assert format_currency(12345) == "$12,345"