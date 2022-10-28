
FROM gcc:latest as build

ADD ./src /app/src
ADD Makefile /app

WORKDIR /app

RUN make all


FROM ubuntu:latest

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

WORKDIR /app

COPY --from=build /app/build/levenshtein .

ENTRYPOINT ["./levenshtein"]
