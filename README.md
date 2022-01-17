# MiniCTF

## Idee
One time pad

$c_1 \oplus c_2 = m_1 \oplus k \oplus m_2 \oplus k = m_1 \oplus m_2$

gegeben: encrypted key

```
send_flag
send_message(1..10)
reset_key
```

### exploit
keylength herausfinden durch kontinuierliches message senden

$keylength - flaglength = rest$

zu lösen: 
$x \text{ mod } keylength = rest$
$x = a*m_1 + b*m_2 + ...$ 

keylength bekommt man durch ausprobieren
weil messages sind gegeben

```
123456789012345678901234567890
flag13371337133713371337133713
371337133713371337133713371337
1337
```

### Implementierung
- in C
- studis bekommen das binary, wo sie ausprobieren können, mit anderem Key und Flag, der aber die gleiche Länge hat
- beim Server können sie dann ihren funktionierenden Exploit ausprobieren

#### Aufgabenverteilung
- Docker 
- Implementierung
- Story


- 
