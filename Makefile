name=test
dest=/usr/bin
cc=gcc
flags=
s = ./
o = ./obj
deps = $(wildcard *.h)
scrs = $(s)/$(wildcard *.c)
objs = $(patsubst %.c,$(o)/%.o,$(scrs))
dir = mkdir $(o)

$(o)/%.o: %.c $(deps)
	-$(dir)
	$(cc) $(flags) -c -o $@ $< 

$(name): $(objs)
	$(cc) $(flags) -o $@ $^ 

install:
	cp $(name) $(dest)/$(name)

clean:
	-rm pack
	-rm -r $(o) $(name)

package:
	tar -czf p.tgz --exclude=obj --exclude=$(name) *
	printf "echo \"" > pack
	base64 -i p.tgz >> pack
	printf "\" | base64 -d -i - | tar -xzf - && rm pack && echo Done" >> pack
	-rm p.tgz
	python3 -m http.server
