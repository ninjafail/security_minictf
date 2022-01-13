# MiniCTF
web

## Idee 1
Website, auf der nur authentifizierte User eine Cross Site Scripting Vulnerability ausführen können. Um sich zu authentifizieren muss eine SQL Injection ausgenutzt werden.

#### 1. Schritt
SQL Injection um nen authetifizierten Usesr zu bekommen

#### 2. Schritt
Als authentifizierter User zugriff auf die Subdomain bekommen, um dort die XSS vuln. ausnutzen zu können

--> Flag kann über ne Funktion geprintet werden


### Was brauchen wir
- nen Webserver mit Subdomain
- ne SQL datenbank für authentifizierte User,
- Frontend mit der Schwachstelle
- Backend mit der Flag


## Idee 2
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