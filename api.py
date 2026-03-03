def quote(ticker):
    key = open('auth.txt','r').read()
    return f'https://financialmodelingprep.com/stable/quote?symbol={ticker}&apikey={key}'

def historical(ticker):
    key = open('auth.txt','r').read()
    return f'https://financialmodelingprep.com/stable/historical-price-eod/light?symbol={ticker}&apikey={key}'

def treasuries():
    key = open('auth.txt','r').read()
    return f'https://financialmodelingprep.com/stable/treasury-rates?apikey={key}'

def news():
    key = open('auth.txt','r').read()
    return f'https://financialmodelingprep.com/stable/fmp-articles?page=0&limit=100&apikey={key}'