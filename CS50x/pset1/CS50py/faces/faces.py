def main():
    text = input()
    text = convert(text)
    print(text)

def convert(t):
    t = t.replace(":)", "🙂")
    t = t.replace(":(", "🙁")
    return (t)

main()
